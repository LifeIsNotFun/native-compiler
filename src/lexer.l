%{
  #include <iostream>

  #include "parser.h"
%}

%option noyywrap

%%

"int" { return INT; }
"char" { return CHAR; }
"void" { return VOID; }
"return" { return RETURN; }

"*" { return ASTERISK; }
"," { return COMMA; }
";" { return SEMICOLON; }

"(" { return LEFT_PARENTHESIS; }
")" { return RIGHT_PARENTHESIS; }
"{" { return LEFT_BRACKET; }
"}" { return RIGHT_BRACKET; }

\"[^\"]+\" { yylval.string = strdup(yytext); return STRING_LITERAL; }
[0-9]+ { yylval.integer = atoi(yytext); return INTEGER_LITERAL; }

[a-zA-Z]+ { yylval.string = strdup(yytext); return IDENTIFIER; }

[ \t\n] ;
. ;

%%
