
/****************************************************************
 Ella Grady
 February 7, 2022
 CS170
 File: main.c
 ------------
 A main program to demonstrate the Stack ADT.
 It pushes and pops numbers as told by the input
 
*/

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(){
    Stack stack = createStack();
    
    char command;
    printf("(i)nsert#, (p)op, (q)uit: ");
    scanf("\n%c", &command);
    int num;
    

    while (command != 'q') {
        
        
        
        if (command == 'i') {
            scanf("%d", &num);
            // printf("push\n");
            push(stack, num);
            // printf("after push\n");
            printStack(stack);
            printf("\n");
        }
        else if (command == 'p') {
            if (!isEmpty(stack)) {
                pop(stack);
                if(isEmpty(stack)) {
                    printf("Empty stack.\n");
                }
                else {
                    printStack(stack);
                    printf("\n");
                }
            }
            else {
                printf("pop from empty stack failed.\n");
            }
        }
        printf("(i)nsert#, (p)op, (q)uit: ");
        scanf("\n%c", &command);
    }
    if (command == 'q') {
        deleteStack(stack);
        return 0;
    }
    
}
