#ifndef NOF 
#define NOF 5
#endif

extern void* exit_func(void *);
extern void* init_func(void *);
extern void* parent_task(void *);
extern void* child_task(void *);
extern void* create_pipe(void *);

extern void* (*fptr[NOF])(void *);

