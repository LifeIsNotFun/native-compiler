#ifndef EXPRESSION_STATEMENT_H
#define EXPRESSION_STATEMENT_H

#include "node.h"
#include "statement.h"

class ExpressionStatement : public Statement {
private:
    Expression *expression;
public:
    explicit ExpressionStatement(Expression *expression) : expression(expression) {}

    inline void print(Context *context) override {
        expression->print(context);
    }
};

#endif /* EXPRESSION_STATEMENT_H */
