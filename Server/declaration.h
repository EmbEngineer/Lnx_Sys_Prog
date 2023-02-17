#include<semaphore.h>
#ifndef NOF
#define NOF 6
#endif

extern sem_t sem;                               //initialized thread semaphore structure.
extern int flag;
void shutdownHandler(int,siginfo_t*,void*);     //siginfo_ structure  void* for null
extern void* creatInfra(void*);
extern void* exitFunc(void*);
extern void* shutdownServer(void*);
extern void* signalCheck(void*);
extern void* proRequest(void*);
extern void* cptureRequest(void*);

extern void* (*fptr[NOF])(void*);
int init();
