#ifndef FUNCTIONEXPRESSION_H
#define FUNCTIONEXPRESSION_H

#include "expression.h"
#include "expressionlist.h"
#include "node.h"

class FunctionExpression : public Expression {
private:
    char *identifier;
    ExpressionList *expressionList;

public:
    FunctionExpression(char *identifier, ExpressionList *expressionList)
            : identifier(identifier), expressionList(expressionList) {}

    virtual void print(Context *context) override {
        expressionList->print(context);

        std::cout << "\t" << "callq _" << identifier << std::endl;
    }
};

#endif /* FUNCTIONEXPRESSION_H */
