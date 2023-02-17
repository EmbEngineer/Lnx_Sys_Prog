#! /bash/bin

MailBox: Open_File.o Child_Task.o Parent_Task.o Init_Func.o Exit_Func.o main.o 
	gcc -o MailBox Open_File.o Child_Task.o Parent_Task.o Init_Func.o Exit_Func.o main.o
open_file.o: Open_File.c declarations.h headers.h
	gcc -c Open_File.c
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
	-rm MailBox

