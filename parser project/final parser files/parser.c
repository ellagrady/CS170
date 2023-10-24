//
//  parser.c
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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lexer.h"
#include "parser.h"

// make the SExpression
SExp makeexpression() {
    SExp expression = malloc(sizeof(*expression));
    expression->pointer = makecell();
    return expression;
}
// make the conscell
conscell makecell()
{
    conscell cell = malloc(sizeof(*cell));
    if (cell == NULL)
    {
        printf("Out of memory.\n");
        exit(1);
    }
    cell->data[0] = '\0';
    cell->first = NULL;
    cell->rest = NULL;
    return cell;
}

// run to make SExpression based on user input
SExp S_Expression()
{
    char token[20];
    startTokens(20);
    printf("\n\n");
    printf("scheme> ");
    SExp expression = makeexpression();
    // get next token
    strcpy(token, getToken());
    conscell current = makecell();
    conscell point = expressionhelper(current, token);
    // puts(point->data);
    expression->pointer = point;
    // puts(expression->pointer->data);
    return expression;
    
}

// check if input is a list
int list = 0;
// helper for S_Expression
conscell expressionhelper(conscell current, char* token)
{
    
    conscell localcell;
    conscell tempcell;
    //if token is "("
    if (!strcmp(token, "("))
    {
        // list check
        list += 1;
        
        // create new local conscell
        localcell = makecell();
        
        // skip over (
        strcpy(token, getToken());
        
        // recursive call for next token to put in next cell
        localcell->first = expressionhelper(localcell, token);
        
        // get next token
        strcpy(token, getToken());
        
        // store the cell
        tempcell = localcell;
        
        // rest of conscell on same level
        while (strcmp(token, ")"))
        {
            tempcell->rest = makecell();
            // recursive call to next token on level
            tempcell = tempcell->rest;
            tempcell->first = expressionhelper(tempcell, token);
            
            // get next token
            strcpy(token, getToken());
        }
        // mark end of level as NULL
        tempcell->rest = NULL;
        // printf("%d\n", list);
        // return the level
        return localcell;
    }
    // handle the data
    else{
        // put data with cell
        strcpy(current->data, token);
        if (list == 0)
        {
            current->first = current;
        }
        // return the cell
        // puts(current->data);
        return current;
    }
}

// printSExp function
void printSExp(SExp expression)
{
    if (list > 1)
    {
        printSExphelper(expression->pointer, 0);
    }
    else{
        printSExphelper(expression->pointer, 1);
    }
    list = 0;

}
// helper for printing expression
void printSExphelper(conscell pointer, int booleanmarker)
{
    // base case
    if (pointer == NULL)
    {
        // booleanmarker for end of list
        if (booleanmarker == 1 && list > 1)
        {
            printf(")");
        }
        return;
    }
    conscell current = pointer;
    conscell next;
    // if cell is beginning
    if (!strcmp(current->data, ""))
    {
        //write the (
        if (booleanmarker == 0)
        {
            printf("(");
        }
        // recursive call to next level
        printSExphelper(current->first, 0);
        // store the cell
        next = current;
        // print out the rest of level
        while (next != NULL)
        {
            next = next->rest;
            // print space if there is next
            if (next != NULL)
            {
                // if next is list
                if (!strcmp(next->data, ""))
                {
                    printf(" ");
                    printSExphelper(next->first, 0);
                }
                // else break  loop
                else
                {
                    printSExphelper(next->first, 1);
                    break;
                }
            }
            else
            {
                // print the next on level
                printSExphelper(next, 1);
            }
        }
    }
    // if cell already not beginning
    else
    {
        
        // write ( if beginning of level
        if (booleanmarker == 0)
        {
            printf("(");
        }
        // print data
        printf(" %s", current->data);
        // print space if there is end
        if (current->rest == NULL)
        {
            printf(" ");
        }
        // print space if next is list
        else if (!strcmp(current->rest->data, ""))
        {
            printf(" ");
        }
        // print the next cell in current level
        printSExphelper(current->rest, 1);
        return;
    }
}



/* part 1

int n = 0;
void S_Expression() {
    char token[20];
    startTokens(20);
    printf("scheme> ");
    strcpy(token, getToken());
    expressionhelper(token);
    return;
}
void expressionhelper(char *token) {
    // if token = "("
    if (!strcmp(token, "(")) {
        // printf("%i\n", n );
        
        // tab space
        for (int i=0; i< n; i++) {
            printf("  ");
        }
        // print S_Expression
        printf("S_Expression\n");
        // tab space
        for (int i=0; i< n; i++) {
            printf("  ");
        }
        //print "("
        printf("%s\n", token);
        // if token is "(" increase tab space by 1
        n = n + 1;
        // printf("%i\n", n );
        // get next token
        strcpy(token, getToken());
        // recursive call for next token
        expressionhelper(token);
        // if token is not ")" continue recursive calls on next token
         while (strcmp(token, ")")){
            expressionhelper(token);
        }
        // if token is ")" decrease tab spacing by 1
         if (!strcmp(token, ")")){
            expressionhelper(token);
        }
            
        n = n - 1;
        // printf("%i\n value of n", n );
            
        // tab spacing
        for (int i=0; i < n; i++) {
            printf("  ");
        }
        // print ")"
        printf("%s\n", token);
        // if tab space is 0 (meaning end of input) return
        if (n==0) {
            return;
        }
        // otherwise go to next token
        else {
            strcpy(token, getToken());
            // expressionhelper(token);
        }
        
    
    }
    
    else {
        // tab space
        for (int i=0; i< n; i++) {
            printf("  ");
        }
        // pring S_Expression
        printf("S_Expression\n  ");
        // tab space
        for (int i=0; i< n; i++) {
            printf("  ");
        }
        // print letters
        printf("%s\n", token);
        // return if n == 0 (end of input)
        if (n==0) {
            return;
        }
        else {
            strcpy(token, getToken());
            // expressionhelper(token);
        }
        
    }
}
void printSExpr(SExp s) {
    
}

 int n = 0;
 void S_Expression() {
     char token[20];
     startTokens(20);
     printf("scheme> ");
     strcpy(token, getToken());
     expressionhelper(token);
     return;
 }
 void expressionhelper(char *token) {
     // if token = "("
     if (!strcmp(token, "(")) {
         // printf("%i\n", n );
         
         // tab space
         for (int i=0; i< n; i++) {
             printf("  ");
         }
         // print S_Expression
         printf("S_Expression\n");
         // tab space
         for (int i=0; i< n; i++) {
             printf("  ");
         }
         //print "("
         printf("%s\n", token);
         // if token is "(" increase tab space by 1
         n = n + 1;
         // printf("%i\n", n );
         // get next token
         strcpy(token, getToken());
         // recursive call for next token
         expressionhelper(token);
         // if token is not ")" continue recursive calls on next token
          while (strcmp(token, ")")){
             expressionhelper(token);
         }
         // if token is ")" decrease tab spacing by 1
          if (!strcmp(token, ")")){
             expressionhelper(token);
         }
             
         n = n - 1;
         // printf("%i\n value of n", n );
             
         // tab spacing
         for (int i=0; i < n; i++) {
             printf("  ");
         }
         // print ")"
         printf("%s\n", token);
         // if tab space is 0 (meaning end of input) return
         if (n==0) {
             return;
         }
         // otherwise go to next token
         else {
             strcpy(token, getToken());
             // expressionhelper(token);
         }
         
     
     }
     
     else {
         // tab space
         for (int i=0; i< n; i++) {
             printf("  ");
         }
         // pring S_Expression
         printf("S_Expression\n  ");
         // tab space
         for (int i=0; i< n; i++) {
             printf("  ");
         }
         // print letters
         printf("%s\n", token);
         // return if n == 0 (end of input)
         if (n==0) {
             return;
         }
         else {
             strcpy(token, getToken());
             // expressionhelper(token);
         }
         
     }
 }
 
void S_Expression() {
    
    // char *token;
    int n = 0;
    char token[20];
    startTokens(20);

    
    strcpy(token, getToken());
    // if token = '('
    if (strcmp(token, "(" )) {

        
        // print S_Expression
        puts("S_Expression\n"); // S_Expression();
        // tab spacing
        for (int i = 0; i < n; i++) {
            puts("  ");
        }
        // print token
        puts(token);
        // if token = '(' increase tab spacing
        n++;
        // next token
        // strcpy(token, getToken());
        // recursive call on next token
        S_Expression();
        // if token != ')' continue recursive on next token
        while(!strcmp(token, ")")) {
            // strcpy(token, getToken());
            S_Expression();
        }
        // if token = ')' decrease tab space by 1
        n-=1;
        // tab spacing
        for (int i = 0; i < n; i++) {
            puts("  ");
        }
        // print token
        puts(token);
        // return if n = 0 (end of input)
        if(n==0) {
            return;
        }
        // otherwise continue with next token
        else{
            strcpy(token, getToken());
        }
        
    }
    else {
        // tab spacing
        for (int i = 0; i < n; i++) {
            puts("  ");
        }
        // print S_Expression
        puts("S_Expression\n");
        // tab spacing
        for (int i = 0; i < n; i++) {
            puts("  ");
        }
        // print token
        puts(token);
        // return if n = 0 (end of input)
        if (n==0) {
            return;
        }
        // otherwise continue with next token
        else {
            strcpy(token, getToken());
        }
    }
}*/


