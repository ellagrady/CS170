
/****************************************************************
 Ella Grady
 February 7, 2022
 CS170
 File: Stack.c
 ----------------
 This file implements the Stack interface given in Stack.h.
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"


/****************************************************************
 The stack is implemented as a linked list of nodes, each
 containing an int stack entry and a pointer to the next node.
*/
struct node { 
	int data;
	struct node *next; 
};
typedef struct node Node;

/****************************************************************
 The state of the stack is encapsulated in this struct, which
 contains a pointer to the head of the stack. The Stack
 ADT is a pointer to a struct of this type.
*/
struct stack {
	Node *head;

};

/*****************************************************************/
Stack createStack()
{ 

	Stack s = (Stack) malloc(sizeof(struct stack));
	
	if (s == NULL) {
		printf("Out of memory!\n");
		exit(1);
	} 
	
	s->head = NULL;
	
	
	return s;
} 

/*****************************************************************/
int isEmpty (Stack s)
{
	return (s->head == NULL);
}

/****************************************************************
 Implementation note: Each pop both removes the element from
 the stack and deallocates the node. The last call to free()
 deallocates the stack struct.
*/
void deleteStack(Stack s)
{ 

	do { 
		pop(s);
	} while (!isEmpty(s));
	
	free(s);
} 

/****************************************************************
 Implementation note: This is a private function for creating
 an stack node pointer with given data contents. It's only
 here to make push() a little easier to read.
*/
static Node *createNode(int data) 
{ 
	Node *node = (Node *) malloc(sizeof(Node));
	
	if (node == NULL) { 
		printf("Out of memory!\n");
		exit(1);
	} 
	
	node->data = data;
	node->next = NULL;

	return node;
} 

/****************************************************************
 Implementation note: Since an empty stack just consists of a
 NULL head, it is necessary to distinguish that as a
 special case. A similar comment holds for pop.
*/
void push(Stack s, int data)
{ 
	Node *node = createNode(data);
	
	if (!isEmpty(s)) {
        
        node->next = s->head;
        s->head = node;
	}
	else {
		s->head = node;
	}
}

/*****************************************************************/
int pop(Stack s)
{ 
	Node *temp;
	int data;

	if (s->head == NULL) {
		// Stack is empty
		return 0;
	} 
	else { 
		temp = s->head;
		s->head = s->head->next;

    

		data = temp->data;
		free(temp);
		return data;
	}
} 

/*****************************************************************/
void printStack (Stack s)
{
	Node *current;

	if (isEmpty(s)) {
		printf("Attempt to print empty stack failed.\n");
		return;
	}

	current = s->head;

	printf("%d  ", current->data);
	while (current->next != NULL) {
		current = current->next;
		printf("%d  ", current->data);
	}
	
}
