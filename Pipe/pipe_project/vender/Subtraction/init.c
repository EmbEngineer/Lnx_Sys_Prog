/**
 *      file    :  init.c
 *      author  :  deepak_jangra
 *      created :  2021 Apr 28 11:00:18  IST
 *      lastMod :  Wednesday 28 April 2021 11:00:18 AM IST
 **/

#include"header.h"
#include"declaration.h"
void* exitFunc(void*);
void* parentTask(void*);
void* childTask(void*);
void* creatInfra(void*);
void* readRequest(void*);
void* proccessRequest(void*);

void* (*fptr[NOF])(void*);

int init()
{
  printf("%s : Begin\n",__func__);

  fptr[0] = exitFunc;
  fptr[1] = childTask;
  fptr[2] = parentTask;
  fptr[3] = creatInfra;
  fptr[4] = readRequest;
  fptr[5] = proccessRequest;
  
  printf("%s : End\n",__func__);
  return 0;
}    

