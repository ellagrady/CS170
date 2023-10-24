//
//  main.c
//  Ella Grady
//  CS170: Parser Project
//  May 2, 2022
//
//  scheme.c runs the user interface
//
//  Created by Ella Grady on 3/2/22.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parser.h"
#include "eval.h"

int main()
{
    // char token[20];

   // startTokens(20);
    // char *input;

    // startTokens(20);


    printf("[MyMachine:cs170/Scheme] ./runschemeI\n");
    printf("A prototype evaluator for Scheme.\n");
    printf("Type Scheme expressions using quote,\n");
    printf("car, cdr, cons and symbol?.\n");
    printf("The function call (exit) quits.");
    // printf("scheme>");
    // printf("Enter any number of lines of input.\n");
    // printf("This will echo tokens as they are found.\n");
    // printf("Terminate by typing \"@@\" (two @\'s in a row).\n");


    //strcpy(token, getToken());
    one = makecell();
    one->first = one;
    variable = one;
    
    while(1)
    {
        //SExp expression1 = makeexpression();
        //strcpy(expression1->pointer, "(a b c)");
        //SExp exp2 = makeexpression();
        //strcpy(exp2->pointer, "(d e)");
        printSExp(eval(S_Expression()));
    }
    return 0;
    /* one = createConsCell();
    one->first=one;
    variable = one;
    

    while (1)
        {
            // printf("%s\n", token);
            // strcpy(token, getToken());
            // printf("scheme>");
            printSExp(S_Expression());
            /* conscell expression = S_Expression();
            SExp express;
            puts(expression);
            express->pointer = expression;
            printSExp(express); */
        
 

}
