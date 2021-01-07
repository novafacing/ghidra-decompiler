#include <iostream>
#include <cstdlib>
#include <sstream>

#include "libdecomp.hh"

class IfcLoadFile : public IfaceDecompCommand {
    public:
        virtual void execute(istream &s);
};

void IfcLoadFile::execute(istream &s) {
    string filename,target;

    if (dcp->conf != (Architecture *)0) 
        throw IfaceExecutionError("Load image already present");
    s >> filename;
    if (!s.eof()) {		// If there are two parameters
        target = filename;		// Second is filename, first is target
        s >> filename;
    }
    else
        target = "default";

    ArchitectureCapability *capa = ArchitectureCapability::findCapability(filename);
    if (capa == (ArchitectureCapability *)0)
        throw IfaceExecutionError("Unable to recognize imagefile "+filename);
    dcp->conf = capa->buildArchitecture(filename,target,status->optr);
    // Attempt to open file and discern
    // the processor architecture  
    DocumentStorage store;	// temporary storage for xml docs

#ifdef CPUI_RULECOMPILE
    if (dcp->experimental_file.size() != 0) {
        *status->optr << "Trying to parse " << dcp->experimental_file << " for experimental rules" << endl;
        try {
            Element *root = store.openDocument(dcp->experimental_file)->getRoot();
            if (root->getName() == "experimental_rules")
                store.registerTag(root);
            else
                *status->optr << "Wrong tag type for experimental rules: "+root->getName() << endl;
        }
        catch(XmlError &err) {
            *status->optr << err.explain << endl;
            *status->optr << "Skipping experimental rules" << endl;
        }
    }
#endif
    string errmsg;
    bool iserror = false;
    try {
        dcp->conf->init(store);
    } catch(XmlError &err) {
        errmsg = err.explain;
        iserror = true;
    } catch(LowlevelError &err) {
        errmsg = err.explain;
        iserror = true;
    }
    if (iserror) {
        *status->optr << errmsg << endl;
        *status->optr << "Could not create architecture" << endl;
        delete dcp->conf;
        dcp->conf = (Architecture *)0;
        return;
    }
    if (capa->getName() == "xml")		// If file is xml
        dcp->conf->readLoaderSymbols(); // Read in loader symbols
#ifdef OPACTION_DEBUG
    dcp->conf->setDebugStream(status->optr);
#endif
    *status->optr << filename << " successfully loaded: " << dcp->conf->getDescription() << endl;
}


int main(int argc, char ** argv) {
    if (argc != 3) {
        exit(1);
    }
    vector<string> extrapaths;
    extrapaths.push_back("./specfiles");
    string ghidraroot = FileManage::discoverGhidraRoot(argv[0]);
    if (ghidraroot.size() == 0) {
        const char * sleighhomepath = getenv("SLEIGHHOME");
        if (sleighhomepath != NULL) {
            ghidraroot = sleighhomepath;
        }
    }

    startDecompilerLibrary(ghidraroot.c_str(), extrapaths);

    stringstream cmdseq;
    cmdseq << "load file " << argv[1] << "\n";
    cmdseq << "read symbols\n";
    cmdseq << "produce C " << argv[2] << "\n";

    IfaceStatus * status = new IfaceTerm("", cmdseq, cout);
    IfaceCapability::registerAllCommands(status);
    status->registerCom(new IfcLoadFile(), "load", "file");

    IfaceDecompData * dcp = (IfaceDecompData *) status->getData("decompile");

    execute(status, dcp);
    execute(status, dcp);
    execute(status, dcp);

    shutdownDecompilerLibrary();
}
