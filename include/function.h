#ifndef FUNCTION_H
#define FUNCTION_H

#include "node.h"
#include "compoundstatement.h"
#include "parameterlist.h"

class Function : public Node {
private:
    int type;
    char *identifier;
    ParameterList *parameterList;
    CompoundStatement *compoundStatement = nullptr;

public:
    Function(int type, char *identifier, ParameterList *parameterList)
            : type(type), identifier(identifier), parameterList(parameterList) {}

    Function(int type, char *identifier, ParameterList *parameterList,
             CompoundStatement *compoundStatement)
            : type(type), identifier(identifier), parameterList(parameterList),
              compoundStatement(compoundStatement) {}

    inline void print(Context *context) override {
        if (compoundStatement == nullptr) {
            // Function declaration
            return;
        }

        // Function definition
        std::cout << ".globl _" << identifier << std::endl;
        std::cout << "_" << identifier << ":" << std::endl;

        // Function prologue
        std::cout << "\t" << "pushq %rbp" << std::endl;
        std::cout << "\t" << "movq %rsp, %rbp" << std::endl;

        compoundStatement->print(context);

        // Function epilogue
        std::cout << "\t" << "popq %rbp" << std::endl;
        std::cout << "\t" << "retq" << std::endl;

        std::cout << std::endl;
    }
};

#endif /* FUNCTION_H */
