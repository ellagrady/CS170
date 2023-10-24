//
//  main.c
//  schemeparser
//
//  Created by Ella Grady on 3/2/22.
//

#include <stdio.h>
#include "parser.h"

int main()
{
    // char token[20];

   // startTokens(20);
    // char *input;

    // startTokens(20);

    printf("A parser for a subset of Scheme.\n");
    printf("Type any Scheme expression and its\n");
    printf("'parse tree' will be printed out.\n");
    printf("Type Ctrl-c to quit.\n");
    // printf("scheme>");
    // printf("Enter any number of lines of input.\n");
    // printf("This will echo tokens as they are found.\n");
    // printf("Terminate by typing \"@@\" (two @\'s in a row).\n");


    //strcpy(token, getToken());
    // S_Expression();

    while (1)
        {
            // printf("%s\n", token);
            // strcpy(token, getToken());
            //printf("scheme>");
            S_Expression();
        }
 

}
