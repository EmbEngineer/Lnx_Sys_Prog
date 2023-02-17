#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

int main(int argc, char* argv[])
{
  int wfd5, rfd6, ret, *result , rs; 
  request *r;
  init();

  printf("ADDER Begin : %s\n",__FILE__);
  wfd5 = atoi(argv[1]);
  rfd6 = atoi(argv[2]);

  r = (request*)malloc(sizeof(request));
  if(!r)
  {
     perror("malloc");
     (*fptr[0])((void*)"failure");
  }

  printf("WRITE FILE DISCRIPTOR IN ADDER %d\n", wfd5);
  printf("READ FILE DISCRIPTOR IN ADDER %d\n", rfd6);

  ret = read(rfd6 , r , sizeof(request));
  if(ret == -1)
  {
	  perror("read");
          (*fptr[0])((void*)"failure");
  }
  printf("number of byte read at vender %d\n",ret);  

  rs = r->opr1 + r->opr2;
  result = &rs;
  ret = write(wfd5 , result , sizeof(int));
  if(ret == -1)
  {
	  perror("write");
          (*fptr[0])((void*)"failure");
  }
  printf("number of byte write from  vender to server %d\n",ret);  
  printf("ADDER END : %s\n",__FILE__);
  return 0;
}    

