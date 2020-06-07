#include "literalexpression.h"

void LiteralExpression::print(Context *context) {
    if (context->isReturnExpression()) {
        if (string == nullptr) {
            std::cout << "\t"
                      << "movl $" << std::setbase(0x10) << integer << ", "
                      << "%eax" << std::endl;
        } else {
            context->addStringLiteral(string);
            std::cout << "\t"
                      << "leaq " << context->getStringLiteral(string) << "(%rip), "
                      << "%rax" << std::endl;
        }
    } else {
        if (string == nullptr) {
        } else {
            context->addStringLiteral(string);
            std::cout << "\t"
                      << "leaq " << context->getStringLiteral(string) << "(%rip), "
                      << "%rdi" << std::endl;
        }
    }
}