#ifndef RETURN_STATEMENT_H
#define RETURN_STATEMENT_H

#include "node.h"
#include "statement.h"

class ReturnStatement : public Statement {
private:
    Expression *expression;

public:
    explicit ReturnStatement(Expression *expression) : expression(expression) {}

    inline void print(Context *context) override {
        context->setReturnExpression(true);
        expression->print(context);
        context->setReturnExpression(false);
    }
};

#endif /* RETURN_STATEMENT_H */
