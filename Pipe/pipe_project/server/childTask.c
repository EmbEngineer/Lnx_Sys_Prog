#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

void* childTask(void* arg)
{
  int i,wfd1,rfd2;
  int* arr;
  char wfd[4];
  char rfd[4];

  printf("Begin : %s\n",__func__);
  proc *pr = (proc*)arg;

  wfd1 = *(pr->pipe + 1);
  rfd2 = *(pr->pipe + 2);

  printf("WRITE FILE DESCRIPTOR : %d\n",wfd1);
  printf("READ FILE DESCRIPTOR : %d\n",rfd2);

  sprintf(wfd,"%d",wfd1);
  sprintf(rfd,"%d",rfd2);
  
  execl("rc_one","rc_one",wfd,rfd,NULL);
  
  printf("End : %s\n",__func__);
  return 0;
}    

