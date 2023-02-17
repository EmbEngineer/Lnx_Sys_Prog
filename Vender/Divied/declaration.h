#ifndef NOF 
#define NOF 3
#endif

extern union semun sem_union[1];

extern void *shmptr;
extern int shkey_vpt;

extern void *smvt_ptr;
extern int smvt_key;

int init();

extern void* exitFunc(void*);
extern void * workOnRequest(void *arg);

extern void* (*fptr[NOF])(void*);
