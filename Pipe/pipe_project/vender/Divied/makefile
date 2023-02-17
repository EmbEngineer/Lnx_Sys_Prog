#! /bin/bash

run: main.o exitFunc.o init.o  childTask.o parentTask.o creatInfra.o readRequest.o proccessRequest.o
	gcc -o run main.o exitFunc.o init.o childTask.o parentTask.o creatInfra.o readRequest.o proccessRequest.o

proccessRequest.o:proccessRequest.c header.h declaration.h
	gcc -c proccessRequest.c 
readRequest.o:readRequest.c header.h declaration.h
	gcc -c readRequest.c 
main.o:main.c header.h declaration.h
	gcc -c main.c 
exitFunc.o:exitFunc.c header.h declaration.h
	gcc -c exitFunc.c 
init.o:init.c header.h declaration.h
	gcc -c init.c 
childTask.o:childTask.c header.h declaration.h
	gcc -c childTask.c 
parentTask.o:parentTask.c header.h declaration.h
	gcc -c parentTask.c 
creatInfra.o:creatInfra.c header.h declaration.h
	gcc -c creatInfra.c

move:
	mv ./run ../
