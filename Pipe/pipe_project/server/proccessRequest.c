#include"header.h"
#include"declaration.h"
#include"dataStruct.h"

void* proccessRequest(void* arg)
{
  int ret,wfd5,rfd6,wret , rret, result;
  char rsfd[4], wsfd[4];
  proc *ptr_rq;

  printf("Begin : %s\n",__FILE__);
  ptr_rq = (proc*)arg;

  ret = fork();

  switch(ret)
  {
         case -1:
             perror("fork");
             (*fptr[0])((void*)"failure");
         case 0:
              switch(ptr_rq->r->opr)
              {
                  case '+':
	          {
                      sprintf(wsfd,"%d",*(ptr_rq->pipe+5));
                      sprintf(rsfd,"%d",*(ptr_rq->pipe+6));
                      wret = write(*(ptr_rq->pipe+7), ptr_rq->r , sizeof(request));
		      if(wret == -1)
		      {
			      perror("write");
            		      (*fptr[0])((void*)"failure");
		      }	      
		      printf("number of byte written to vender %d\n",wret); 
                      execl("./vender/Adder/adder","adder",wsfd,rsfd,NULL);
		      break;
		  }
		  case '-':
                     execl("./subtr","subtr",wsfd,rsfd,NULL);
                     break;
                  case '*':
                     execl("./multi","multi",wsfd,rsfd,NULL);
                     break;
                  case '/':
                     execl("./divid","divid",wsfd,rsfd,NULL);
                     break;
                  case '%':
                     execl("./modul","modul",wsfd,rsfd,NULL);
                     break;
		  default:
		     break;   
              }
         default:
               rret = read(*(ptr_rq->pipe+4), &result , sizeof(int));
	       if(rret == -1)
	       {
	             perror("read");
                     (*fptr[0])((void*)"failure");
	       }	      
	       printf("number of byte read from vender at server %d\n",rret);
               rret = write(*(ptr_rq->pipe+3), &result , sizeof(int));
	       if(rret == -1)
	       {
	             perror("write");
                     (*fptr[0])((void*)"failure");
	       }	      
	       printf("number of byte write from server to  client %d\n",rret);

	     break;
  }
  printf("End : %s\n",__FILE__);
  return (void*)ptr_rq;
}    

