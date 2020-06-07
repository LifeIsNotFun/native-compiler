#ifndef STATEMENT_LIST_H
#define STATEMENT_LIST_H

#include "node.h"
#include "statement.h"

class StatementList : public Node {
private:
    StatementList *statementList;
    Statement *statement;
public:
    StatementList(StatementList *statementList, Statement *statement) : statementList(statementList),
                                                                        statement(statement) {}

    inline void print(Context *context) override {
        if (statementList != nullptr) {
            statementList->print(context);
        }

        statement->print(context);
    }
};

#endif /* STATEMENT_LIST_H */
