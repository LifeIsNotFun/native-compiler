#ifndef LITERAL_EXPRESSION_H
#define LITERAL_EXPRESSION_H

#include "expression.h"
#include "node.h"

#include <iomanip>

class LiteralExpression : public Expression {
private:
    char *string = nullptr;
    int integer = 0;

public:
    explicit LiteralExpression(char *string) : string(string) {}

    explicit LiteralExpression(int integer) : integer(integer) {}

    void print(Context *context) override;
};

#endif /* LITERAL_EXPRESSION_H */
