#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

void* creatInfra(void* arg)
{
  int* temp;
  int i,pret;
  printf("Begin : %s\n",__func__);
  temp = (int*)malloc(sizeof(int)*8);
  if(!temp)
  {
    perror("malloc");
    (*fptr[0])((void*)"failure");
  }
  for(i = 0 ; i < 4 ; i++)
  {
     pret = pipe(temp + (i*2));
     if(pret == -1)
     {
         perror("pipe");
         (*fptr[0])((void*)"failure");
     }
  }
  printf("End : %s\n",__func__);
  return (void*)temp;
}    

