#! /bin/bash/

CFLAGS=-c 
LPTHREAD=-lpthread

server:main.o creatInfra.o exitFunc.o init.o shutdownHandler.o shutdownServer.o signalCheck.o processRequest.o cptureRequest.o
	gcc -o server main.o creatInfra.o exitFunc.o init.o shutdownHandler.o shutdownServer.o signalCheck.o processRequest.o cptureRequest.o -lpthread

signalCheck.o:signalCheck.c ../Common/headers.h headers.h ../Common/dataStruct.h declaration.h
	gcc $(CFLAGS) signalCheck.c $(LPTHREAD)
shutdownHandler.o:shutdownHandler.c ../Common/headers.h headers.h ../Common/dataStruct.h declaration.h
	gcc $(CFLAGS) shutdownHandler.c
shutdownServer.o:shutdownServer.c ../Common/headers.h headers.h ../Common/dataStruct.h declaration.h
	gcc $(CFLAGS) shutdownServer.c
main.o:main.c ../Common/headers.h headers.h ../Common/dataStruct.h declaration.h
	gcc $(CFLAGS) main.c $(LPTHREAD)
creatInfra.o:creatInfra.c ../Common/headers.h headers.h ../Common/dataStruct.h declaration.h
	gcc $(CFLAGS) creatInfra.c $(LPTHREAD)
exitFunc.o:exitFunc.c ../Common/headers.h declaration.h
	gcc $(CFLAGS) exitFunc.c
init.o:init.c ../Common/headers.h headers.h declaration.h ../Common/dataStruct.h
	gcc $(CFLAGS) init.c
processRequest.o:processRequest.c ../Common/headers.h headers.h ../Common/dataStruct.h declaration.h
	gcc $(CFLAGS) processRequest.c $(LPTHREAD)
cptureRequest.o:cptureRequest.c ../Common/headers.h headers.h ../Common/dataStruct.h declaration.h
	gcc $(CFLAGS) cptureRequest.c $(LPTHREAD)

clean:
	-rm *.o 
