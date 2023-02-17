#include"../Common/headers.h"
#include"headers.h"
#include"../Common/dataStruct.h"
#include"declaration.h"

void* cptureRequest(void* arg)
{
	Infra *infra;
	int ret;
	Result *res;

	printf("%s : BEGIN\n",__func__);
	
	infra = (Infra*)arg;	
		
	res = (Result *)shmat(infra->shmid,(void*)0,0);   
        if(res == (void *)-1)
        {
              perror("shmat");
              (*fptr[0])((void*)"failure");
        }
	
        while(1)
	{	
		ret = sem_wait((sem_t *)smvt_ptr);
       		if(ret == -1)
        	{
              		perror("sem_wait");
              		(*fptr[0])((void*)"failure");
        	}
		ret = msgsnd(infra->msgid, res ,sizeof(res->result) , 0);
		if(ret == -1)
        	{
        		perror("msgsnd");
                	(*fptr[0])((void*)"failure");
        	}
		printf("%s : Resdult :- %d and Send to Client Successfully\n",__func__, res->result); 
	}

	printf("%s:END  \n",__func__);
	pthread_exit(NULL);

//	return 0 ;
}
