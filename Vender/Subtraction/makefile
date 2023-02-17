#! /bin/bash

subtr: exitFunc.o init.o main.o workOnRequest.o
	gcc -o subtr exitFunc.o init.o main.o workOnRequest.o -lpthread

main.o:main.c ../../Common/dataStruct.h header.h declaration.h ../../Common/headers.h
	gcc -c main.c -lpthread
exitFunc.o:exitFunc.c declaration.h header.h ../../Common/headers.h ../../Common/dataStruct.h
	gcc -c exitFunc.c 
init.o:init.c declaration.h header.h ../../Common/headers.h ../../Common/dataStruct.h
	gcc -c init.c 
workOnRequest.o: workOnRequest.c header.h declaration.h ../../Common/dataStruct.h ../../Common/headers.h
	gcc -c workOnRequest.c -lpthread

clean:
	rm *.o
	#rm -adder
