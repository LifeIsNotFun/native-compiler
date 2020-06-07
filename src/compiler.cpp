#include "compiler.h"
#include "parser.h"

int main(void) {
  yyin = fopen("hello.c", "r");
  if (!yyin) {
    std::cerr << "file opener failed" << std::endl;
    return 1;
  }

  yyparse();

  return 0;
}
