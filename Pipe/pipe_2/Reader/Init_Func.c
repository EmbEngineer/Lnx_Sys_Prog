#include "headers.h"
#include "declarations.h"

void* exit_func(void *);
void* init_func(void *);
void* parent_task(void *);
void* child_task(void *);
void* create_pipe(void *);

void* (*fptr[NOF])(void *);

void * init_func(void* arg)
{
      printf("Begin: %s\n",__func__ );
      fptr[0] = exit_func;
      printf("End: %s\n",__func__ );
     return NULL;
}

