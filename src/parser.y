%{
  #include <iostream>

  int yylex();
  void yyerror(char const *error);

  #include "compiler.h"
%}

%defines

%union {
  char *string;
  int integer;

  class LiteralExpression *literalExpression;
  class CompoundStatement *compoundStatement;
  class ExpressionList *expressionList;
  class Expression *expression;
  class ExpressionStatement *expressionStatement;
  class Function *function;
  class FunctionExpression *functionExpression;
  class FunctionList *functionList;
  class Node *node;
  class Parameter *parameter;
  class ParameterList *parameterList;
  class Pointer *pointer;
  class ReturnStatement *returnStatement;
  class Statement *statement;
  class StatementList *statementList;
}

%type <literalExpression> literalExpression
%type <compoundStatement> compoundStatement
%type <expressionList> expressionList
%type <expression> expression
%type <expressionStatement> expressionStatement
%type <function> function
%type <functionExpression> functionExpression
%type <functionList> functionList
%type <parameter> parameter
%type <parameterList> parameterList
%type <pointer> pointer
%type <returnStatement> returnStatement
%type <statement> statement
%type <statementList> statementList

%type <integer> type

%token INT CHAR VOID
%token RETURN

%token LEFT_PARENTHESIS RIGHT_PARENTHESIS
%token LEFT_BRACKET RIGHT_BRACKET

%token <string> IDENTIFIER

%token ASTERISK
%token SEMICOLON
%token COMMA

%token <string> STRING_LITERAL
%token <integer> INTEGER_LITERAL

%start parser

%%

parser: functionList {
    Context *context = new Context();
    context->printHeader();

    $1->print(context);

    context->printFooter();
    delete context;
  }
  ;

functionList:
  function {
    $$ = new FunctionList(nullptr, $1);
  }
  | functionList function {
    $$ = new FunctionList($1, $2);
  }
  ;

function:
  type IDENTIFIER LEFT_PARENTHESIS parameterList RIGHT_PARENTHESIS SEMICOLON {
    $$ = new Function($1, $2, $4);
  }
  | type IDENTIFIER LEFT_PARENTHESIS parameterList RIGHT_PARENTHESIS compoundStatement {
    $$ = new Function($1, $2, $4, $6);
  }
  ;

type:
  INT {

  }
  | CHAR {

  }
  | VOID {

  }
  ;

parameterList:
  parameter {

  }
  | parameterList COMMA parameter {

  }
  ;

parameter:
  type {

  }
  | pointer {

  }
  ;

pointer:
  type ASTERISK {

  }
  | pointer ASTERISK {

  }

statementList:
  statement {
    $$ = new StatementList(nullptr, $1);
  }
  | statementList statement {
    $$ = new StatementList($1, $2);
  }
  ;

statement:
  compoundStatement {
    $$ = $1;
  }
  | expressionStatement SEMICOLON {
    $$ = $1;
  }
  | returnStatement SEMICOLON {
    $$ = $1;
  }
  ;

compoundStatement:
  LEFT_BRACKET statementList RIGHT_BRACKET {
    $$ = new CompoundStatement($2);
  }
  ;

expressionStatement:
  expression {
    $$ = new ExpressionStatement($1);
  }
  ;

expression:
  functionExpression {

  }
  | literalExpression {

  }
  ;

functionExpression:
  IDENTIFIER LEFT_PARENTHESIS expressionList RIGHT_PARENTHESIS {
    $$ = new FunctionExpression($1, $3);
  }
  ;

literalExpression:
  INTEGER_LITERAL {
    $$ = new LiteralExpression($1);
  }
  | STRING_LITERAL {
    $$ = new LiteralExpression($1);
  }
  ;

expressionList:
  expression {
    $$ = new ExpressionList(nullptr, $1);
  }
  | expressionList COMMA expression {
    $$ = new ExpressionList($1, $3);
  }
  ;

returnStatement:
  RETURN expression {
    $$ = new ReturnStatement($2);
  }
  ;

%%

void yyerror(char const *error) {
  std::cerr << error << std::endl;
}
