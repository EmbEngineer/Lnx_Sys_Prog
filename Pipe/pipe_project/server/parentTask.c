#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

void* parentTask(void* arg)

{
  int i;
  proc* ptr_rq;
  printf("Begin : %s\n",__func__);
  ptr_rq = (proc*)arg;
  (*fptr[4])((void*)ptr_rq);     //read request
  (*fptr[5])((void*)ptr_rq);     //processReq
  sleep(1);
  printf("End : %s\n",__func__);
  return 0;
}    

