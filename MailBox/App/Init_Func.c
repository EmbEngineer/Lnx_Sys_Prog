#include "headers.h"
#include "declarations.h"

void* exit_func(void *);
void* init_func(void *);
void* task(void *);

void* (*fptr[NOF])(void *);

void * init_func(void* arg)
{
      printf("Begin: %s\n",__func__ );
      fptr[0] = exit_func;
      fptr[1] = task;
      printf("End: %s\n",__func__ );
     return NULL;
}

