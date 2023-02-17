#include "headers.h"
#include "declarations.h"

void* exit_func(void *);
void* init_func(void *);
void* parent_task(void *);
void* child_task(void *);
void* open_file(void *);

void* (*fptr[NOF])(void *);

void * init_func(void* arg)
{
      printf("Begin: %s\n",__func__ );
      fptr[0] = exit_func;
      fptr[1] = parent_task;
      fptr[2] = child_task;
      fptr[3] = open_file;
      printf("End: %s\n",__func__ );
     return NULL;
}

