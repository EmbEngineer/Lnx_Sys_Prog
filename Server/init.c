#include"../Common/headers.h"
#include"../Common/dataStruct.h"
#include"headers.h"
#include"declaration.h"

int flag;
sem_t sem;
int smvt_key;
void *smvt_ptr;

void shutdownHandler(int,siginfo_t*,void*);

void* creatInfra(void*);
void* exitFunc(void*);
void* shutdownServer(void*);
void* signalCheck(void*);
void* proRequest(void*);
void* cptureRequest(void*);
void* (*fptr[NOF])(void*);

int init()
{
	flag = 0;
	fptr[0] = exitFunc;
	fptr[1] = creatInfra;
	fptr[2] = shutdownServer;
	fptr[3] = signalCheck;
	fptr[4] = proRequest;
	fptr[5] = cptureRequest;

return 0;
}
