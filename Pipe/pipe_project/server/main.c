#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

int main()
{
  int pret,i,fret;
  proc *ptr_req;          // struct with pipe and request struct
  
  printf("Begin : %s\n",__func__);
  init();
 
  ptr_req = (proc*)malloc(sizeof(proc));
  if(!ptr_req)
  {
    perror("malloc");
    (*fptr[0])((void*)"failure");

  }
  printf("PID : %d PPID : %d\n",getpid(),getppid());
  ptr_req->pipe = (int*)(*fptr[3])(0);      // creatInfra used for create wight pipe pointer

  for(i = 0 ; i < 3 ; i++)
  {
     fret = fork();
     printf("FORK RETURN : %d\n", fret);
     switch(fret)
     {
        case -1:
	     perror("fork");
             (*fptr[0])((void*)"failure");
             break; 
      	case 0:
             printf("------------- C H I L D -- S T A R T-----------------");
             (*fptr[1])((void*)ptr_req); //childTask
             break;
        default:
             printf("------------- P A R E N T -- S T A R T-----------------");
             (*fptr[2])((void*)ptr_req); //parentTask
             break;
     }

   }
  printf("%s : End\n",__func__);
  return 0;
}    

