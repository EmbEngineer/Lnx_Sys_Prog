#include "../../Common/headers.h"
#include "header.h"
#include "../../Common/dataStruct.h"
#include "declaration.h"

int smvt_key;
void *smvt_ptr;

int shkey_vpt;
void *shmptr;

union semun sem_union[1];

void* (*fptr[NOF])(void*);

void* exitFunc(void*);
void * workOnRequest(void *arg);

int init()
{
  printf("Begin : %s\n",__func__);

  fptr[0] = exitFunc;
  fptr[1] = workOnRequest;
  
  printf("End : %s\n",__func__);
  return 0;
}    

