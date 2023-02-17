#ifndef NOF 
#define NOF 3
#endif

extern void* exit_func(void *);
extern void* init_func(void *);
extern void* task(void *);

extern void* (*fptr[NOF])(void *);

