#ifndef FUNCTIONLIST_H
#define FUNCTIONLIST_H

#include "function.h"
#include "node.h"

class FunctionList : public Node {
private:
    FunctionList *functionList = nullptr;
    Function *function;

public:
    inline FunctionList(FunctionList *functionList, Function *function)
            : functionList(functionList), function(function) {}

    inline void print(Context *context) override {
        if (functionList != nullptr) {
            functionList->print(context);
        }

        function->print(context);
    }
};

#endif /* FUNCTIONLIST_H */
