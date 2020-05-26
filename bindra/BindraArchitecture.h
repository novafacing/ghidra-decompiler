#ifndef BINDRA_ARCHITECTURE_H
#define BINDRA_ARCHITECTURE_H

#include "architecture.hh"
#include "sleigh_arch.hh"

#include <vector>
#include <map>
#include <string>

class BindraArchitecture : public SleighArchitecture {
    private:
        std::map<std::string, VarnodeData> registers;
        std::vector<std::string> warnings;
        bool rawptr = false;
        void loadRegisters(const Translate * translate);
    public:
        explicit BindraArchitecture(const std::string &sleigh_id);
        ProtoModel * protoModelFromBindraCC(const char * cc);
        Address registerAddressFromBindraReg(const char * regname);
        void addWarning(const std::string & warning) {
            warnings.push_back(warning);
        }
        const std::vector<std::string> getWarnings() const {
            return warnings;
        }
        ContextDatabase * getContextDatabase();
        void setRawPtr(bool rawptr) {
            this->rawptr = rawptr;
        }
    protected:
        Translate * buildTranslator(DocumentStorage & store) override;
        void buildLoader(DocumentStorage & store) override;
        Scope * buildGlobalScope() override;
        void buildTypegrp(DocumentStorage & store) override;
        void buildCommentDB(DocumentStorage & store) override;
        void postSpecFile() override;
        void buildAction(DocumentStorage & store) override;
};


#endif /* BINDRA_ARCHITECTURE_H */
