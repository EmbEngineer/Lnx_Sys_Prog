#include"../Common/headers.h"
#include"headers.h"
#include"../Common/dataStruct.h"
#include"declaration.h"
void* proRequest(void* arg) 
{
	Infra *infra;
	int ret, fret;
	char clientId[8];
	Request_Mq req_mq;
	Result *res;

	printf("%s : BEGIN\n",__func__);
	
	infra = (Infra*)arg;
	
/*	fd = open("servfifo",O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		(*fptr[0])((void*)"failure");
	}
*/
	ret = read( infra->fifo_fd, &req_mq, sizeof(Request_Mq));
	if(ret == -1)
	{
		perror("read");
		(*fptr[0])((void*)"failure");
	}
      

	printf("%s : ++++++++++++++++++++++++++++ Request Received ++++++++++++++++++++\n",__func__);

//	close(fd);

	ret = sem_post(&sem);
	if(ret != 0)
	{
		perror("sem_post");
		(*fptr[0])((void*)"failure");
	}
	
	printf("%s : opr :- %c\n",__func__,req_mq.req.opr);
	printf("%s : op1 :- %d\n",__func__,req_mq.req.op1);
	printf("%s : op2 :- %d\n",__func__,req_mq.req.op2);  

	fret = fork();
	if(fret == 0)
	{
			switch(req_mq.req.opr)
			{
				case '+':
                     		         sprintf(clientId,"%ld", req_mq.clientpid);
                     			 ret = execl("./adder","adder", clientId, NULL);
				         if(ret == -1)
					 {
                          		      perror("execl");
                           	     	      (*fptr[0])((void*)"failure");
					 }
					 break;
				case '-':
                     		         sprintf(clientId,"%ld", req_mq.clientpid);
                     			 ret = execl("./subtr","subtr", clientId,NULL);
				         if(ret == -1)
					 {
                          		      perror("execl");
                           	     	      (*fptr[0])((void*)"failure");
					 }
					break;
				case '*':
                     		         sprintf(clientId,"%ld", req_mq.clientpid);
                     			 ret = execl("./multi","multi", clientId,NULL);
				         if(ret == -1)
					 {
                          		      perror("execl");
                           	     	      (*fptr[0])((void*)"failure");
					 }
					break;
				case '/':
                     		         sprintf(clientId,"%ld", req_mq.clientpid);
                     			 ret = execl("./dvdr","dvdr", clientId,NULL);
				         if(ret == -1)
					 {
                          		      perror("execl");
                           	     	      (*fptr[0])((void*)"failure");
					 }
					break;
				default:
					break;
		         }
	}
	

	pthread_mutex_lock(&infra->wt_lock);
  
	ret = msgsnd(infra->msgid_sv, &req_mq ,sizeof(req_mq.req) , 0);
        if(ret == -1)
        {
               perror("msgsnd");
               (*fptr[0])((void*)"failure");
        }

/*	ret = write(*(infra->pipesFds+1), &r , sizeof(Request));
        if(ret == -1)
        {
              perror("write");
              (*fptr[0])((void*)"failure");
        }
*/	
	pthread_mutex_unlock(&infra->wt_lock);
		
	printf("%s:END  \n",__func__);
	pthread_exit(NULL);

}
