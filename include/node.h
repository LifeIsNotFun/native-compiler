#ifndef NODE_H
#define NODE_H

#include "context.h"

class Node {
private:
public:
    virtual void print(Context *context) = 0;
};

#endif /* NODE_H */
