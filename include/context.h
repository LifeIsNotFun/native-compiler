#ifndef CONTEXT_H
#define CONTEXT_H

#include <iostream>

#include <map>
#include <vector>

#include <algorithm>
#include <iterator>

#include <iomanip>
#include <sstream>

class Context {
private:
    unsigned int stringIndex = 0;

    bool returnExpression = false;
    std::map<char *, char *> stringMap;

    char *nextString();

public:
    Context() = default;

    static void printHeader();

    void addStringLiteral(char *stringLiteral);

    char *getStringLiteral(char *stringLiteral);

    void printFooter();

    void setReturnExpression(bool expression);

    bool isReturnExpression() const;
};

#endif /* CONTEXT_H */
