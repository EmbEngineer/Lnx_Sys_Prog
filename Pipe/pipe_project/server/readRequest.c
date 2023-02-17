#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

void* readRequest(void* arg)
{
  int ret,rfd;
  proc* ptr_rq;
  request *r;
  
  printf("Begin : %s\n",__func__);
  ptr_rq = (proc*)arg;
  ptr_rq->r = (request*)malloc(sizeof(request));
  if(!ptr_rq->r)
  {
     perror("malloc");
     (*fptr[0])((void*)"failure");
  }

  rfd = *(ptr_rq->pipe + 0);
  printf("read fd  %d\n", *(ptr_rq->pipe + 0));
  ret = read(rfd,ptr_rq->r,sizeof(request));
  if(ret == -1)
  {
    perror("read");
    (*fptr[0])((void*)"failure");
  }

  printf("Number of bytes to be read : %d\n", ret);

  printf("End : %s\n",__func__);
  return 0;
}    




