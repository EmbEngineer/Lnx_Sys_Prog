#! /bash/bin

reader: Init_Func.o Exit_Func.o main.o 
	gcc -o reader Init_Func.o Exit_Func.o main.o
Init_Func.o: Init_Func.c declarations.h headers.h
	gcc -c Init_Func.c
Exit_Func.o: Exit_Func.c declarations.h headers.h
	gcc -c Exit_Func.c 
main.o: main.c declarations.h headers.h
	gcc -c main.c

clean:
	-rm *.o
	-rm reader

