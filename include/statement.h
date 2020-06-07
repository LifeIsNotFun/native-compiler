#ifndef STATEMENT_H
#define STATEMENT_H

#include "node.h"

class Statement : public Node {
private:
public:
    virtual void print(Context *context) = 0;
};

#endif /* STATEMENT_H */
