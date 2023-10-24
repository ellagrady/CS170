//
//  parser.h
//  Ella Grady
//  CS170: Parser Project
//  May 2, 2022
//
//  parser.c makes the expressions, conscells,
//  and reads through input to make the corresponding SExpression
//
//
//  Created by Ella Grady on 2/21/22.
//

#ifndef PARSER
#define PARSER
#include <stdlib.h>
//define conscell type

typedef struct conscell
{
    char data[20];
    struct conscell *first;
    struct conscell *rest;
}*conscell;
typedef struct SExp
{
    struct conscell *pointer;
    
} *SExp;
 int list;
 conscell one;
 conscell variable;
SExp makeexpression();
conscell makecell();
SExp S_Expression();
conscell expressionhelper(conscell current, char* token);
void printSExp(SExp expression);
void printSExphelper(conscell pointer, int booleanmarker);



#endif /* parser_h */

/* #ifndef parser_h
#define parser_h

#include <stdio.h>
typedef struct conscell
{
    char data[20];
    struct conscell *first;
    struct conscell *rest;
} *conscell;

typedef struct SExp
{
    struct conscell *pointer;
} *SExp;
int list;
conscell one;
conscell variable;
conscell makecell();
conscell expressionhelper();
SExp S_Expression();
void printSExp(SExp s);
void helpprint(conscell spoinnter, int num);
// void S_Expression();
// void expressionhelper(char *token);

#endif  parser_h */
