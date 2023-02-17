#ifndef NOF 
#define NOF 6
#endif

int init();
extern void* exitFunc(void*);
extern void* childTask(void*);
extern void* parentTask(void*);
extern void* creatInfra(void*);
extern void* readRequest(void*);
extern void* proccessRequest(void*);

extern void* (*fptr[NOF])(void*);
