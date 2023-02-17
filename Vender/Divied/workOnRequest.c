#include "../../Common/headers.h"
#include "header.h"
#include "../../Common/dataStruct.h"
#include "declaration.h"

void * workOnRequest(void *arg)
{
	long trgt_pid;
        int ret, mqId;	
	Result *resptr;
	Request_Mq req_mq;	
	struct sembuf sem_buf;

	printf("%s : Begin \n",__func__);

	trgt_pid = *(long *)arg;
 
        mqId = msgget((key_t)5, IPC_CREAT|0666);
        if(mqId == -1)
        {
                perror("msgget");
		(*fptr[0])((void*)"failure");
        }

        ret = msgrcv(mqId, &req_mq, sizeof(req_mq.req), trgt_pid , 0);
        if(ret == 0)
        {
                perror("msgrcv");
		(*fptr[0])((void*)"failure");

        }

/*	ret = read(fd , &req , sizeof(Request));
 	if(ret == -1)
  	{
		perror("read");
	  	exit(EXIT_FAILURE);
  	}
*/	
	printf("%s : Vender opr :- %c\n",__func__,req_mq.req.opr);
        printf("%s : Vender op1 :- %d\n",__func__,req_mq.req.op1);
        printf("%s : Vender op2 :- %d\n",__func__,req_mq.req.op2);
 
	if(req_mq.req.opr != '/')
	{
		printf("%s : Invalid operation!!\n",__func__);
		(*fptr[0])((void*)"failure");

	}


	sem_buf.sem_num = 0;
        sem_buf.sem_op = -1;                   // decrement shemaphore variable
        sem_buf.sem_flg = SEM_UNDO;
        if(semop(shkey_vpt, &sem_buf, 1) == -1)
        {
                perror("semop");
		(*fptr[0])((void*)"failure");

        }

 	resptr = (Result *)shmptr;
  	resptr->clientPid = (long)req_mq.clientpid;
  	resptr->result = req_mq.req.op1 / req_mq.req.op2;

	sem_post((sem_t *)smvt_ptr);

	sem_buf.sem_num = 0;
        sem_buf.sem_op = 1;                   // Increment shemaphore variable
        sem_buf.sem_flg = SEM_UNDO;
	
	printf("%s :**************************** End-1 ******************************\n",__func__);
        
	if(semop(shkey_vpt, &sem_buf, 1) == -1)
        {
		perror("semop");
		(*fptr[0])((void*)"failure");

        }
        
	printf("%s :**************************** End-2 ******************************\n",__func__);
        return 0;
}
