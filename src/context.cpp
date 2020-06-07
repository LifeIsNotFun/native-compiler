#include "context.h"

char *Context::nextString() {
    std::stringstream stringStream;
    stringStream << "lstr" << std::setbase(10) << stringIndex++;
    char *string = strdup(stringStream.str().c_str());
    return string;
}

void Context::printHeader() {
    std::cout << ".text" << std::endl;
}

void Context::addStringLiteral(char *stringLiteral) {
    auto iterator = stringMap.find(stringLiteral);
    if (iterator == stringMap.end()) {
        stringMap[stringLiteral] = nextString();
    }
}

char *Context::getStringLiteral(char *stringLiteral) {
    auto iterator = stringMap.find(stringLiteral);
    if (iterator != stringMap.end()) {
        return stringMap[stringLiteral];
    } else {
        return nullptr;
    }
}

void Context::printFooter() {
    std::vector<char *> keyVector;
    transform(stringMap.begin(), stringMap.end(), back_inserter(keyVector),
              [](const std::map<char *, char *>::value_type &value) {
                  return value.first;
              });

    for (char *key : keyVector) {
        std::cout << stringMap[key] << ": .asciz " << key << std::endl;
    }
}

void Context::setReturnExpression(bool expression) {
    Context::returnExpression = expression;
}

bool Context::isReturnExpression() const { return Context::returnExpression; }
