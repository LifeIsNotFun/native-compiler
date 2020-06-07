#ifndef EXRESSION_H
#define EXRESSION_H

#include "node.h"

class Expression : public Node {
private:
public:
    void print(Context *context) override = 0;
};

#endif /* EXRESSION_H */
