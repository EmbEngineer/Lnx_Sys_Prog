#! /bash/bin

Pipe_Test: Create_Pipe.o Child_Task.o Parent_Task.o Init_Func.o Exit_Func.o main.o 
	gcc -o Pipe_Test Create_Pipe.o Child_Task.o Parent_Task.o Init_Func.o Exit_Func.o main.o

Create_Pipe.o: Create_Pipe.c declarations.h headers.h
	gcc -c Create_Pipe.c
Child_Task.o: Child_Task.c declarations.h headers.h
	gcc -c Child_Task.c
Parent_Task.o: Parent_Task.c declarations.h headers.h
	gcc -c Parent_Task.c
Init_Func.o: Init_Func.c declarations.h headers.h
	gcc -c Init_Func.c
Exit_Func.o: Exit_Func.c declarations.h headers.h
	gcc -c Exit_Func.c 
main.o: main.c declarations.h headers.h
	gcc -c main.c

clean:
	-rm *.o
	-rm Pipe_Test

