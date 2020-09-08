#include "libdecomp.hh"
#include "loadimage.hh"
#include "sleigh.hh"
#include "xml.hh"
#include "printc.hh"
#include "raw_arch.hh"

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
    std::vector<string> extrapaths({"./specfiles", "./specs/"});
    startDecompilerLibrary(nullptr);


    shutdownDecompilerLibrary();
}
