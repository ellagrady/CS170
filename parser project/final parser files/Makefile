# Makefile
# Ella Grady
# CS170: Parser Project
# May 2, 2022
#
#
# This is the Makefile for Parser Project
# To compile, simply type "make" at the command line.
# To remove all object code, type "make clean" (this removes
# all ".o" and ".a" files)

# Executable file "exec" depends on main.o and IntQueue.o

scheme: scheme.o lexer.o parser.o eval.o
	gcc -o scheme lexer.o parser.o scheme.o eval.o

	


parser.o: parser.c
	gcc -c parser.c

scheme.o: scheme.c
	gcc -c scheme.c

	
lexer.o: lexer.c
	gcc -c lexer.c
	
eval.o: eval.c
	gcc -c eval.c

clean:
	rm -f *~ *.o *.a
	
	
#To run, put this file together with lexer.h, and lexer.c
#in the same directory. Run "make". Then the executable
#is "schemer," which just takes a line of input and
#breaks it up into tokens.

#^^^^^^This space must be a TAB!!.


#^^^This space must be a TAB!!.


