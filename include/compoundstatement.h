#ifndef COMPOUND_STATEMENT_H
#define COMPOUND_STATEMENT_H

#include "node.h"
#include "statement.h"
#include "statementlist.h"

class CompoundStatement : public Statement {
private:
    StatementList *statementList;

public:
    explicit CompoundStatement(StatementList *statementList)
            : statementList(statementList) {}

    void print(Context *context) override;
};

#endif /* COMPOUND_STATEMENT_H */
