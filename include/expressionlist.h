#ifndef EXPRESSION_LIST_H
#define EXPRESSION_LIST_H

#include "node.h"

class ExpressionList : public Node {
private:
    ExpressionList *expressionList;
    Expression *expression;

public:
    ExpressionList(ExpressionList *expressionList, Expression *expression)
            : expressionList(expressionList), expression(expression) {}

    inline void print(Context *context) override {
        if (expressionList != nullptr) {
            expressionList->print(context);
        }

        expression->print(context);
    }
};

#endif /* EXPRESSION_LIST_H */
