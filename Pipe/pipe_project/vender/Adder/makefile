#! /bin/bash

adder: exitFunc.o init.o main.o  
	gcc -o adder exitFunc.o init.o main.o 	
main.o:main.c header.h declaration.h
	gcc -c main.c
exitFunc.o:exitFunc.c header.h declaration.h
	gcc -c exitFunc.c 
init.o:init.c header.h declaration.h
	gcc -c init.c 

clean:
	rm *.o
	rm adder
