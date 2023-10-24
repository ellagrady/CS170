//
//  eval.h
//  Ella Grady
//  CS170: Parser Project
//  May 2, 2022
//
//  eval.h includes all of the functions to evaluate the
//  built in scheme functions, some helpers for them, and the
//  universal eval() function that reads the input and calls
//  the necessary function
//
//  Created by Ella Grady on 3/16/22.
//

#ifndef eval_h
#define eval_h
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parser.h"

SExp globalenvironment;
int numge;

SExp functionalenvironment;
int numfe;

SExp quote(SExp expression);
SExp car(SExp expression);
SExp cdr(SExp expression);
SExp symbol(SExp expression);
SExp cons(SExp expression1, SExp expression2);
SExp append(SExp expression1, SExp expression2);
SExp null(SExp expression);
SExp equals(SExp expression1, SExp expression2);
int equalhelp(SExp expression1, SExp expression2);
SExp assoc(SExp symbol, SExp pairlist);
SExp stringassoc(char* symbol, SExp list);
SExp cond(SExp expression);
SExp define(SExp symbolname, SExp value);
SExp function(SExp expression, SExp value);
SExp listcheck(SExp expression);
SExp functioncheck(SExp expression);
SExp functioneval(SExp expression);

SExp eval(SExp expression);



#endif /* eval_h */
