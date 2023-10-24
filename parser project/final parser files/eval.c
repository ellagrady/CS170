//
//  eval.c
//  Ella Grady
//  CS170: Parser Project
//  May 2, 2022
//
//  eval.c includes all of the functions to evaluate the
//  built in scheme functions, some helpers for them, and the
//  universal eval() function that reads the input and calls
//  the necessary function
//
//  Created by Ella Grady on 3/16/22.
//
#include <stdlib.h>
#include <string.h>
#include "eval.h"

// symbol environment
SExp globalenvironment;
int numge;

// function environment
SExp functionalenvironment;
int numfe;

// return the expression - don't evaluate the expression
SExp quote(SExp expression) {

    return expression;
   
}
// returns first symbol in list
SExp car(SExp expression) {
    conscell cell = expression->pointer;
    SExp returnexp = makeexpression();
    returnexp->pointer = cell;
    if (cell == NULL) {
        return NULL;
    }
    if (strcmp(cell->data, "")) {
        conscell tempcell = makecell();
        tempcell->first = tempcell;
        strcpy(tempcell->data, cell->data);
        returnexp->pointer = tempcell->first;
        return returnexp;
    }
    else {
        returnexp->pointer = cell->first;
        return returnexp;
    }

}
// returns rest of list
SExp cdr(SExp expression) {
    conscell cell = expression->pointer;
    SExp returnexp = makeexpression();
    if (cell == NULL) {
        return NULL;
    }

    returnexp->pointer = cell->rest;
    return returnexp;
}
// returns true if input is a symbol, false otherwise
SExp symbol(SExp expression) {
    if (expression->pointer != NULL) {
        SExp result = makeexpression();
        strcpy(result->pointer->data, "#t");
        return result;
    }
    else {
        SExp result = makeexpression();
        strcpy(result->pointer->data, "#f");
        return result;
    }
    
}

// puts two expressions together into one list
SExp cons(SExp expression1, SExp expression2) {
    SExp one = makeexpression();
    SExp two = makeexpression();
    if (cdr(expression1)->pointer == NULL) {
        one->pointer = car(expression1)->pointer->first;
    }
    else {
        one->pointer->first = expression1->pointer;
    }
    two->pointer->first = expression2->pointer;
    // check if expression1 is false or empty
    if (!strcmp(car(one)->pointer->data,  "()") && !strcmp(car(one)->pointer->data,"#f")) {
        // if both are false, return an empty List
        if (!strcmp(car(two)->pointer->data, "()") && !strcmp(car(two)->pointer->data,"#f")) {
            return makeexpression();
            
        }
    // just expression1 is false, return expression2
        return two;
    }
    // check to see if the expression2 is false, if so return expression1
    if (!strcmp(car(two)->pointer->data , "()") && !strcmp(car(two)->pointer->data,"#f") ) {
        return one;
    }
    // otherwise cons the two valid entries
    if (strcmp(car(two)->pointer->data , "()")) {
        one->pointer->rest = car(two)->pointer;
    }
    return one;
}
// puts two expressions together into one list
SExp append(SExp expression1, SExp expression2) {
    if (expression2->pointer == NULL || !strcmp(expression2->pointer->data, "()")) {
            if (expression1->pointer == NULL || !strcmp(expression1->pointer->data, "()")) {
                return makeexpression();
            }
        
            return expression1;
    }
    if (expression1->pointer == NULL || !strcmp(expression1->pointer->data, "()")) {
        return expression2;
    }
    // both are valid lists.
    SExp a = expression1;
    if (cdr(a)->pointer != NULL ) { // if the list has a rest, get to the last rest
        SExp temp = cdr(a);
        while (cdr(temp)->pointer != NULL) {
            temp = cdr(temp);
        }
        temp->pointer->rest = expression2->pointer;  // set the last rest to point to the copy of b
    } else {
        a->pointer->rest = append(car(expression2), cdr(expression2))->pointer;  //
    }
    return a;
}
// returns true if expression is null or empty, false otherwise
SExp null(SExp expression) {
    list = 1;
    if (expression->pointer == NULL) {
        SExp result = makeexpression();
        strcpy(result->pointer->data, "#t");
        return result;
    }
    if (expression->pointer != NULL) {
        if (!strcmp(expression->pointer->data, "#f") || !strcmp(expression->pointer->data, "()")) {
            SExp result = makeexpression();
            strcpy(result->pointer->data, "#t");
            return result;
        }
    }
    SExp result = makeexpression();
    strcpy(result->pointer->data, "#f");
    return result;
}

// returns true if the expressions are equal to each other
SExp equals(SExp expression1, SExp expression2) {
    SExp temp = makeexpression();
    list = 0;
    if (equalhelp(expression1, expression2) == 1) {
        temp->pointer->first = temp->pointer;
        strcpy(temp->pointer->first->data, "#t");
        return temp;
    }
    else {
        temp->pointer->first = temp->pointer;
        strcpy(temp->pointer->first->data, "#f");
        return temp;
    }
}
// helper for equals
int equalhelp(SExp expression1, SExp expression2) {
    if (expression1->pointer == NULL) {
        if (expression2->pointer == NULL) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (expression2->pointer == NULL) {
        if (expression1->pointer == NULL) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (!strcmp(expression1->pointer->data, expression2->pointer->data)) {
        if(strcmp(car(expression1)->pointer->data, expression1->pointer->data)) {
            int n;
            if (strcmp(car(expression1)->pointer->data, expression2->pointer->data)) {
                n = equalhelp(car(expression1), car(expression2));
            }
            else {
                return 0;
            }
            int o = equalhelp(cdr(expression1), cdr(expression2));
            if (n == 0 || o == 0) {
                return 0;
            }
            else {
                return 1;
            }
        }
        else {
            return equalhelp(cdr(expression1), cdr(expression2));
        }
    }
    else {
        return 0;
    }
}
// checks if symbol is in pairlist
SExp assoc(SExp symbol, SExp pairlist) {
    
    return stringassoc(symbol->pointer->data, pairlist);
    
}
// helper for assoc
SExp stringassoc(char* symbol, SExp pairlist) {
    list = 3;
    while (pairlist != NULL) {
            // get pair
            if ( car(pairlist) != NULL ) {
                SExp pair = car(pairlist);
                // check the first element of pair
                if (car(pair) != NULL) {
                    SExp element = car(pair);
                    // check whether the element is the same as given symbol
                    if (element->pointer != NULL) {
                        if (!strcmp(symbol,element->pointer->data)) {
                            return pair;
                        }
                    }
                }
            }
            // get the next part
            pairlist = cdr(pairlist);
    }
    list = 1;
    SExp result = makeexpression();
    strcpy(result->pointer->data , "#f");
    return result;
}
// multiple conditional
SExp cond(SExp expression) {
    if (expression != NULL && car(expression) != NULL) {
        // sturcture is a pair, first part is the boolean,
        //  second is the part to be executed
        SExp expstruct = car(expression);
        if (car(expstruct) != NULL) {
            SExp boolean = eval(car(expstruct));    // get boolean portion
            // check to see if boolean portion is true
            if ( boolean != NULL && (!strcmp(boolean->pointer->data, "#t") )) {
                SExp rest = cdr(expstruct); // the executable portion
                SExp evalexp = cdr(rest);

                list = 2;
                return eval(car(rest));
            }
        }
        // recursive portion to be called if there is more to the cond statement
        if (cdr(expression) != NULL) {
           // puts(cdr(expression)->pointer->data);
            return cond(cdr(expression));
        }
    }
    SExp result = makeexpression();
    strcpy(result->pointer->data, "#f");
    return result;
}
// define symbol
SExp define(SExp symbolname, SExp value) {
    // if no symbols in global environment make the expression
    if (numge == 0) {
        globalenvironment = makeexpression();
        numge++;
    }
    /*
     cons values onto empty list
     cons values list on to name
     cons full thing onto global */
    SExp param = makeexpression();
    param = cons(value, param);
    symbolname = cons(symbolname, param);
    globalenvironment = cons(symbolname, globalenvironment);

    numge++;
    list = 0;
    return car(car(symbolname));
    
    
}
// define functions
SExp function(SExp funcname, SExp value) {
    // if no functions in global environment make expression
    if (numfe == 0) {
        functionalenvironment = makeexpression();
        
    }
    
    /*
     cons values onto empty list
     cons values list on to name
     cons full thing onto global */

        SExp param = makeexpression();
        param = append(value, param);
        
        SExp rest = makeexpression();
        rest = cons(param, rest);
       
        funcname = cons(funcname, rest);
        SExp hold = makeexpression();
        hold = cons(funcname, hold);
        functionalenvironment = cons(hold, functionalenvironment);


        numfe++;
        return car(car(funcname));
    
    
}
// check if expression is a list - if is return true, else return false
SExp listcheck(SExp expression) {
    SExp temp = makeexpression();
    if (!strcmp(null(cdr(expression))->pointer->data, "#f")) {
        list = 1;
        strcpy(temp->pointer->data, "#t");
        return temp;
    }
    else {
        list = 0;
        strcpy(temp->pointer->data, "#f");
        return temp;
    }
}
// check if expression is defined within global environment
SExp functioncheck(SExp expression) {
    SExp temp = makeexpression();
    if(!strcmp(assoc(expression, functionalenvironment)->pointer->data, "#f")) {
        list = 0;
        strcpy(temp->pointer->data, "#f");
        return temp;
    }
    else {
        list = 0;
        strcpy(temp->pointer->data, "#t");
        return temp;
    }
    
}
/* helper to remove a user defined function for when a new function with same name is added to functionalenvironment */
SExp removefunction(SExp expression) {
    /* puts("remove");
    printSExp(car(car(functionalenvironment)));
    puts("\n");
    printSExp(expression);
    // printSExp(stringassoc(car(cdr(expression))->pointer->data, car(car(functionalenvironment)))); */
    SExp tempenvironment = makeexpression();
   //  puts("temp");
    while(numfe > 0) {
       /*  puts("a");
        // printSExp(functionalenvironment);
        printf("%d\n", numfe);
        
        printSExp(car(car(car(functionalenvironment)))); */
        if(!strcmp(car(car(car(functionalenvironment)))->pointer->data, car(expression)->pointer->data)) {
            numfe--;
            /* puts("b");
            printf("%d\n", numfe); */
            if(numfe == 0) {
                break;
            }
            else {
                /* puts("cdr(functional)");
                printSExp(cdr(functionalenvironment));
                puts("\n"); */
                tempenvironment = cons(cdr(functionalenvironment), tempenvironment);
                /* printSExp(tempenvironment);
                puts("\n");
                printSExp(functionalenvironment);
                puts("\n"); */
            }
            /* printSExp(functionalenvironment);
            puts("\n"); */
            break;
        }
        else {
            tempenvironment = cons(car(functionalenvironment), tempenvironment);
            /* puts("tempenvironment");
            printSExp(tempenvironment);
            puts("\n"); */
            functionalenvironment = cdr(functionalenvironment);
            /* printSExp(functionalenvironment);
            puts("\n"); */
        }
    }
    functionalenvironment = car(tempenvironment);
    /* puts("pre add");
    printSExp(functionalenvironment);
    puts("\n"); */
    return functionalenvironment;
}

// evaluate user defined functions
SExp functioneval(SExp expression) {
   
    SExp definition;
    SExp function;
    definition = (car(cdr(car(assoc(car(expression), functionalenvironment)))));
    function = car(cdr(cdr(definition)));
    SExp parameters = cdr(car(cdr(definition)));

    SExp local = makeexpression();
    int numparms = 0;
    while (parameters->pointer != NULL) {
        SExp pair = makeexpression();
        strcpy(pair->pointer->data, "");
        pair->pointer->first = car(parameters)->pointer;
        pair->pointer->rest = makecell();
        strcpy(pair->pointer->rest->data, "");
        pair->pointer->rest->first = eval(car(cdr(expression)))->pointer;
        pair->pointer->rest->rest = NULL;
        

        local = cons(pair, local);
        expression = cdr(expression);
        parameters = cdr(parameters);
    
        numparms++;

    }
    if (numge == 0){
        globalenvironment = makeexpression();
        numge++;
    }
    while (local->pointer->rest != NULL) {
        globalenvironment = cons(car(local), globalenvironment);

        local = cdr(local);
    }
    SExp result = eval(function);
    for (int i = 0; i < numparms; i++) {
        globalenvironment = cdr(globalenvironment);
    }
    // printSExp(result);
    return result;
}


// eval for all scheme functions
SExp eval(SExp expression) {
    
    conscell pointercell = expression->pointer;
    if (pointercell == NULL)
    {
        return expression;
    }
    SExp tempexp;
    //exit
    if (!strcmp(pointercell->first->data, "exit"))
    {
        printf("Have a nice day!\n");
        printf("[MyMachine:cs170/Scheme]\n");
        exit(0);
    }
        // quote
    if (cdr(expression) != NULL && car(cdr(expression)) != NULL){
     if (!strcmp(pointercell->first->data, "quote") ||!strcmp(pointercell->first->data, "'"))
    {
      
        return quote(car(cdr(expression)));
    }
        //car function
        else if (!strcmp(pointercell->first->data, "car"))
        {
            //eval the rest of the list
            SExp restexp = makeexpression();
            restexp->pointer = pointercell->rest->first;
            tempexp = eval(restexp);
            //check if the car is a list
            if (strcmp(tempexp->pointer->data, ""))
            {
                list = 0;
            }
            return car(eval(car(cdr(expression))));
        }
        //cdr function
        else if (!strcmp(pointercell->first->data, "cdr"))
        {
            //eval the rest of the list
            return cdr(eval(car(cdr(expression))));
        }
        //symbol? function
        else if (!strcmp(pointercell->first->data, "symbol?"))
        {
            //eval the rest of the list
            SExp restexp = makeexpression();
            restexp->pointer = pointercell->rest->first;
            tempexp = eval(restexp);
            //check if input is a list
            if (strcmp(tempexp->pointer->data, "") && tempexp->pointer->rest == NULL)
            {
                list = 0;
            }
            return symbol(tempexp);
        }
        //cons function
        else if (!strcmp(pointercell->first->data, "cons"))
        {
            
            SExp one =eval(car(cdr(expression)));
            
            SExp two =eval(car(cdr(cdr(expression))));
        
            return cons(one, two);
        }
    }
    if (!strcmp(pointercell->first->data, "append")) {
        SExp one =eval(car(cdr(expression)));

        SExp two =eval(car(cdr(cdr(expression))));

        return append(one, two);
    }
    if (!strcmp(pointercell->first->data, "null?")) {
        return null(eval(car(cdr(expression))));
    }
    if (!strcmp(pointercell->first->data, "equal?")) {
        // puts(car(cdr(expression))->pointer->data);
        
        return equals(eval(car(cdr(expression))), eval(car(cdr(cdr(expression)))) );
    }
    if (!strcmp(pointercell->first->data, "assoc")) {
        return assoc(eval(car(cdr(expression))), eval(car(cdr(cdr(expression)))));
    }
    if (!strcmp(pointercell->first->data, "cond")) {
        return cond(cdr(expression));
    }
    if (!strcmp(pointercell->first->data, "define")) {
      
        if(car(cdr(cdr(expression))) != NULL) {
            // if is a function definition
            if (!strcmp((listcheck(car(cdr(expression))))->pointer->data, "#t")) {
                // puts("defining functions");
                /* puts("cdr(expression)");
                printSExp(((cdr(expression))));
                puts("\n"); */
                // if there's not a function with existing name
                 if(!strcmp(stringassoc(car(car(cdr(expression)))->pointer->data, functionalenvironment)->pointer->data, "#f")) {
                   
                    SExp func = cdr(cdr(expression));
                    // printSExp(car(car(cdr(expression))));
                    SExp result = function(car(car(cdr(expression))), expression);
                    /* printSExp(functionalenvironment);
                    puts("\n"); */
                   // printSExp((functionalenvironment));
                    return result;
                }
                else { // redefine function
                    /* printSExp(functionalenvironment);
                    puts("\n");
                    printSExp(car(assoc(car(car(cdr(expression))), functionalenvironment)));
                    puts("\n"); */
                    removefunction(assoc(car(car(cdr(expression))), functionalenvironment));
                    SExp func = cdr(cdr(expression));
                    SExp result = function(car(car(cdr(expression))), expression);
                    // printSExp(functionalenvironment);
                    return result;
                }
                    
                        
            }
                        
                
            
            else { // define symbol
                SExp def = eval(car(cdr(cdr(expression))));
                // printSExp(def);
                
                return define(eval(car(cdr(expression))), def);
               
            }
        }
    }
    if(!strcmp(pointercell->first->data, "list?")) {
        return listcheck(eval(car(cdr(expression))));
    }
    if (!strcmp(pointercell->first->data, "function?")) {
        return functioncheck(eval(car(cdr(expression))));
    }
    // return symbol
    if (strcmp(stringassoc(pointercell->first->data, globalenvironment)->pointer->data, "#f")) {
      //  puts("one");
        SExp def = stringassoc(pointercell->first->data, globalenvironment);
      //  puts("two");
        
        return car(cdr(def));
    }
    
    SExp associatedfunc = assoc(car(expression), functionalenvironment);
    /* puts("associated");
    printSExp(associatedfunc);
    puts("\n");*/
    
    // eval user function
    if (strcmp(associatedfunc->pointer->data, "#f")) {
       
        list = 3;
        
        SExp evaluated = functioneval(expression);
        
        return evaluated;
    }
    list = 2;
    return expression;
    
        
    
}
    


