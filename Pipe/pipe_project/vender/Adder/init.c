#include"header.h"
#include"declaration.h"

int init();
void* exitFunc(void*);
void* (*fptr[NOF])(void*);

int init()
{
  printf(" Begin : %s\n",__func__);

  fptr[0] = exitFunc;
  
  printf("End : %s\n",__func__);
  return 0;
}    

