#include "libdecomp.hh"
#include "loadimage.hh"
#include "sleigh.hh"
#include "xml.hh"
#include "printc.hh"

#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

class AssemblyRaw : public AssemblyEmit
{
	public:
		void dump(const Address &addr, const string &mnem, const string &body) override
		{
			std::stringstream ss;
			addr.printRaw(ss);
			ss << ": " << mnem << ' ' << body;
            std::cout << ss.str().c_str() << std::endl;
		}
};

class PcodeRawOut : public PcodeEmit
{
	private:
		static void print_vardata(ostream &s, VarnodeData &data)
		{
			s << '(' << data.space->getName() << ',';
			data.space->printOffset(s,data.offset);
			s << ',' << dec << data.size << ')';
		}

	public:
		void dump(__attribute__((unused)) const Address &addr, OpCode opc, VarnodeData *outvar, VarnodeData *vars, int4 isize) override
		{
			std::stringstream ss;
			if(outvar)
			{
				print_vardata(ss,*outvar);
				ss << " = ";
			}
			ss << get_opname(opc);
			// Possibly check for a code reference or a space reference
			for(int4 i=0; i<isize; ++i)
			{
				ss << ' ';
				print_vardata(ss, vars[i]);
			}
            std::cout << ss.str().c_str() << std::endl;
		}
};


int main(int argc, char ** argv) {
    if (argc != 2) {
        return 1;
    }
    const char * dpath = argv[1];
    std::vector<string> extrapaths = {"./specfiles"};
    startDecompilerLibrary(std::move(extrapaths));

    ArchitectureCapability * capa = ArchitectureCapability::findCapability(dpath);
    if (capa == nullptr) {
        std::cerr << "Unable to recognize imagefile." << std::endl;
        exit(1);
    }
    Architecture * arch = capa->buildArchitecture(dpath, "default", &std::cerr);
    DocumentStorage store;
    std::string errmsg;
    bool iserror = false;
    try {
        arch->init(store);
    } catch (XmlError &err) {
        errmsg = err.explain;
        iserror = true;
    } catch (LowlevelError &err) {
        errmsg = err.explain;
        iserror = true;
    }

    if (capa->getName() == "xml") {
        arch->readLoaderSymbols();
    }

    if (iserror) {
        std::cerr << errmsg << std::endl;
        std::cerr << "Could not create architecture" << std::endl;
        exit(1);
    } else {
        std::cout << "Created architecture " << arch->getDescription() << " with XML " << std::endl;
        arch->saveXml(std::cout);
    }


    const Translate * trans = arch->translate;
    PcodeRawOut emit;
    AssemblyRaw assememit;
    Address addr(trans->getDefaultCodeSpace(), 0x401112);
    /*
    for (uint64_t i = 0; i < 10; i++) {
        trans->printAssembly(assememit, addr);
        auto length = trans->oneInstruction(emit, addr);
        addr = addr + length;
    }
    */



    Funcdata * f = arch->symboltab->getGlobalScope()->queryFunction(addr);
    if (f == nullptr) {
        std::cerr << "No function in Scope" << std::endl;
        std::cerr << "Bad address: " << addr.getShortcut();
        addr.printRaw(std::cerr);
        std::cout << std::endl << addr.getSpace()->getName() << " may not be a global space in specfile" << std::endl;

        exit(1);
    }

    auto action = arch->allacts.getCurrent();
    int res = -1;
    try {
        action->reset(*f);
        res = action->perform(*f);
    } catch (const LowlevelError &error) {
        std::cerr << "Error performing decompilation" << std::endl;
        exit(1);
    }
    
    if (res < 0) {
        std::cerr << "Decompilation error." << std::endl;
        exit(1);
    }

    shutdownDecompilerLibrary();
}
