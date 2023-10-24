//
//  parser.c
//  
//
//  Created by Ella Grady on 2/21/22.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lexer.h"
#include "parser.h"

 // tab spacing
// char token[20];
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
        /* if (!strcmp(token, ")")){
            expressionhelper(token);
        }*/ 
            
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
        printf("S_Expression\n");
        // tab space
        for (int i=0; i < n; i++) {
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
/* void S_Expression() {
    
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
} */


