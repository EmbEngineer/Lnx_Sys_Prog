#include"header.h"
#include"dataStruct.h"

int main(int argc, char* argv[])
{
  
  int wfd, rfd, ret, result;
  request req;

  printf("RC1 Begin : %s \n",__FILE__);
  
  wfd = atoi(argv[1]);
  rfd = atoi(argv[2]);
  
  printf("WRITE FILE DISCRIPTOR %d\n", wfd);
  printf("READ FILE DISCRIPTOR %d\n", rfd);
  
  req.pid = getpid();
  req.opr = '+';
  req.opr1 = 10;
  req.opr2 = 10;
  ret = write(wfd, &req, sizeof(request));
  if(ret == -1)
  {
       perror("write");   
       exit(EXIT_FAILURE);
  }
  printf("No of bytes  wrote request %d \n",ret);
  ret = read(rfd, &result, sizeof(int));
  if(ret == -1)
  {
       perror("read");   
       exit(EXIT_FAILURE);
  }
  printf("*********************************Result - %d *********************** \n",result);
  printf("RC1 End : %s\n",__FILE__);
  return 0;
}    
