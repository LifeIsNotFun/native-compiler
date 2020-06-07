#include "compoundstatement.h"

inline void CompoundStatement::print(Context *context) {
    statementList->print(context);
}