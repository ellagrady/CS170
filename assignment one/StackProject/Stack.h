
/****************************************************************
 Ella Grady
 February 7, 2022
 CS170
 File: Stack.h
 ----------------
 This is an interface for a stack of integer ADT. The ADT
 supports routines for stack creation, deletion, pushing,
 popping, and printing.
 ****************************************************************/

#ifndef UTILS_STACK
#define UTILS_STACK

/****************************************************************
 Type: Stack
 --------------
 Declaration of an Stack object takes the form,

   Stack s;
 */
 typedef struct stack *Stack;


/****************************************************************
 Function: createStack()
 -----------------------
 Creates a new stack and returns it.

 Example usages:
   Stack s1;
   s1 = createStack();

   Stack s2 = createStack();
 */
 Stack createStack(void);


/****************************************************************
 Function: isEmpty(Stack)
 ---------------------------
 Returns true if the argument is the empty stack, false otherwise.

 Example usage, given the Stack variable s:

   if (!isEmpty(s))
     printf("This is not an empty stack.\n");
 */
 int isEmpty (Stack stack);


/****************************************************************
 Function: deleteStack(Stack)
 -------------------------------
 Destroys the stack given as argument. Always call this after
 an Stack s is no longer needed, as:

    deleteStack(s);
 */
 void deleteStack(Stack stack);

/****************************************************************
 Function: push(Stack, int)
 --------------------------------
 pushes the second argument in the first. The int is put at the
 front of the stack.

 Example usage, given Stack variable s:

    push(s, 2);

 pushes the number 2 at the front of the stack s.
 */
 void push(Stack stack, int data);

/****************************************************************
 Function: pop(Stack)
 ---------------------------
 Removes the item at the front of the stack and returns its value.

 Example usage, given Stack variable s and int variable front:

     front = pop(s);

 If 2 were at the front of the stack, front now contains the
 value 2.

 WARNING: pop will return 0 if an attempt is made to pop
 from the empty stack. It is the client's responsibility to
 determine if the stack is empty before calling pop.
 */
 int pop(Stack stack);

/****************************************************************
 Function: printStack(Stack)
 ------------------------------
 Prints the contents of the stack at the console, starting with
 the front and going to the rear. There is a space between each
 number, and all appear on one line.
 */
void printStack (Stack stack);

#endif
