#include"../Common/headers.h"
#include"headers.h"
#include"../Common/dataStruct.h"
#include"declaration.h"

void* creatInfra(void* arg)
{
	Infra *infra;
	int ret;
	struct shmid_ds *shmds;
	struct msqid_ds *msgds;
	printf("%s: Begin\n",__func__);
	
	infra = (Infra*)malloc(sizeof(Infra));                   //memory allocation to infra struct 
	if(!infra)
	{
		perror("malloc");
		(*fptr[0])((void*)"failure");
	}

	/*************************************** Pipe *****************************************/
	
	infra->pipesFds = (int*)malloc(sizeof(int)*2);
	if(!infra->pipesFds)
	{
		perror("malloc");
		free(infra);
		(*fptr[0])((void*)"failure");
	}
        
	ret = pipe(infra->pipesFds);
	if(ret == -1)
	{
		perror("malloc");
		free(infra->pipesFds);
		free(infra);
		(*fptr[0])((void*)"failure");
	}
	printf("%s: Pipe Successfully Created\n",__func__);
	
	/*****************************************************************************************/



	/************************************** FiFO **********************************************/

	infra->fifoName = (char*)malloc(sizeof(char)*20);
        if(!infra->fifoName)
        {
                perror("malloc");
                free(infra->pipesFds);
                free(infra);
                (*fptr[0])((void*)"failure");
        }
	memset(infra->fifoName,'\0',20);           //now all the block of memory has stored '\0'
        strcpy(infra->fifoName, FIFONAME);

	ret = mkfifo(infra->fifoName, 0666);
	if(ret == -1)
	{
                perror("malloc");
                free(infra);
                free(infra->pipesFds);
                free(infra->fifoName);
                (*fptr[0])((void*)"failure");
	}
	printf("%s: FIFO Successfully Created\n",__func__);
	
        /*********************************************************************************************/



        /*********************************** Shared Memory Result ************************************/

	//args key,size of shared memory,flag ipc create|permission rw.
	infra->shmid = shmget((key_t)SMKEY,sizeof(Result),IPC_CREAT|0666);
	if(infra->shmid == -1)
	{
		perror("shmget");
                free(infra->pipesFds);
                free(infra->fifoName);
                free(infra);
		(*fptr[0])((void*)"failure");
	}

	infra->shrdMem = shmat(infra->shmid,(void*)0,0);
	if(!infra->shrdMem)
	{
		perror("shmat");
                free(infra->pipesFds);
                free(infra->fifoName);
		ret = shmctl(infra->shmid,IPC_RMID,shmds);
		if(ret == -1)
			printf("%s: shmctl() failed\n",__func__);
                free(infra);
		(*fptr[0])((void*)"failure");
	}

	printf("%s: Shared MEmory Successfully Created\n",__func__);

        /************************************************************************************/



	/********************************** Massege Queue-1 ************************************/

	infra->msgid = msgget((key_t)MQKEY,IPC_CREAT|0666);
	if(infra->msgid == -1)
	{
		perror("msgget");
                free(infra->pipesFds);
                free(infra->fifoName);
                shmdt(&infra->shmid);
		ret = shmctl(infra->shmid,IPC_RMID,shmds);
		if(ret == -1)
			printf("%s: shmctl() failed\n",__func__);
		ret = msgctl(infra->msgid,IPC_RMID,msgds);
		if(ret == -1)
			printf("%s: msgctl() failed\n",__func__);
                free(infra);
		(*fptr[0])((void*)"failure");
	}

	printf("%s: Message Queue-1 Successfully Created\n",__func__);

        /***************************************************************************************/


	/********************************** Massege Queue-2 ************************************/

	infra->msgid_sv = msgget((key_t)MQKEY_SV,IPC_CREAT|0666);
	if(infra->msgid_sv == -1)
	{
		perror("msgget");
                free(infra->pipesFds);
                free(infra->fifoName);
                shmdt(&infra->shmid);
		ret = shmctl(infra->shmid,IPC_RMID,shmds);
		if(ret == -1)
			printf("%s: shmctl() failed\n",__func__);
		ret = msgctl(infra->msgid,IPC_RMID,msgds);
		if(ret == -1)
			printf("%s: msgctl() failed\n",__func__);
		ret = msgctl(infra->msgid,IPC_RMID,msgds);
		if(ret == -1)
			printf("%s: msgctl() failed\n",__func__);
                free(infra);
		(*fptr[0])((void*)"failure");
	}

	printf("%s: Message Queue-1 Successfully Created\n",__func__);


	/****************************** Process ShemaPhore  ***********************************/

	infra->semid = semget((key_t)SEMKEY,4,0666|IPC_CREAT);
	if(infra->semid == -1)
	{
		perror("semget");
                free(infra->pipesFds);
                free(infra->fifoName);
                shmdt(&infra->shmid);
		ret = shmctl(infra->shmid,IPC_RMID,shmds);
		if(ret == -1)
			printf("%s: shmctl() failed\n",__func__);
		ret = msgctl(infra->msgid,IPC_RMID,msgds);
		if(ret == -1)
			printf("%s: msgctl() failed\n",__func__);
		ret = semctl(infra->semid,4,IPC_RMID);
		if(ret == -1)
			printf("%s: shmctl() failed\n",__func__);
		ret = msgctl(infra->msgid_sv,IPC_RMID,msgds);
		if(ret == -1)
			printf("%s: msgctl() failed\n",__func__);
                free(infra);
		(*fptr[0])((void*)"failure");
	}
	printf("%s: Process Semaphore Successfully created\n",__func__);		

        /****************************************************************************************/



	/******************** Trread SemaPhore (Main Thread and processReq Thread) *******************/
	 
	ret = sem_init(&sem,0,1);
	if(ret!=0)
	{
		perror("sem_init");
                free(infra->pipesFds);
                free(infra->fifoName);
                shmdt(&infra->shmid);
                ret = shmctl(infra->shmid,IPC_RMID,shmds);
                if(ret == -1)
                        printf("%s: shmctl() failed\n",__func__);
                ret = msgctl(infra->msgid,IPC_RMID,msgds);
                if(ret == -1)
                        printf("%s: msgctl() failed\n",__func__);
                ret = semctl(infra->semid,4,IPC_RMID);
                if(ret == -1)      
	      		printf("%s: shmctl() failed\n",__func__);
		ret = msgctl(infra->msgid_sv,IPC_RMID,msgds);
		if(ret == -1)
			printf("%s: msgctl() failed\n",__func__);
       		sem_close(&sem);
		free(infra);
	      	(*fptr[0])((void*)"failure");
	
	}

	printf("%s: Thread Semaphore Successfully created\n",__func__);		
	

        /**************** Shared Memory for vender and processReq Sem ***************************/
	
	//args key,size of shared memory,flag ipc create|permission rw.
	smvt_key = shmget((key_t)SMKEY_VT ,sizeof(sem_t),IPC_CREAT|0666);
	if(smvt_key == -1)
	{
		perror("shmget");
                free(infra->pipesFds);
                free(infra->fifoName);
                free(infra);
		(*fptr[0])((void*)"failure");
	}

	smvt_ptr = shmat(smvt_key , (void*)0, 0);
	if(!smvt_ptr)
	{
		perror("shmat");
                free(infra->pipesFds);
                free(infra->fifoName);
		ret = shmctl(infra->shmid,IPC_RMID,shmds);
		if(ret == -1)
			printf("%s: shmctl() failed\n",__func__);
                free(infra);
		(*fptr[0])((void*)"failure");
	}

	printf("%s: Shared MEmory Successfully Created\n",__func__);
        
	/*********************************************************************************************/
	
	
	/******************** Thread SemaPhore (Vender Thread and processReq Thread) *************/
	 
	ret = sem_init((sem_t *)smvt_ptr, 1, 0);
	if(ret!=0)
	{
		perror("sem_init");
                free(infra->pipesFds);
                free(infra->fifoName);
                shmdt(&infra->shmid);
                ret = shmctl(infra->shmid,IPC_RMID,shmds);
                if(ret == -1)
                        printf("%s: shmctl() failed\n",__func__);
                ret = msgctl(infra->msgid,IPC_RMID,msgds);
                if(ret == -1)
                        printf("%s: msgctl() failed\n",__func__);
                ret = semctl(infra->semid,4,IPC_RMID);
                if(ret == -1)      
	      		printf("%s: shmctl() failed\n",__func__);
		ret = msgctl(infra->msgid_sv,IPC_RMID,msgds);
		if(ret == -1)
			printf("%s: msgctl() failed\n",__func__);
       		sem_close(&sem);
		free(infra);
	      	(*fptr[0])((void*)"failure");
	
	}

	printf("%s: Thread Semaphore Successfully created\n",__func__);		
	
	/***************************************************************************************/
	
	
	/************************************* Mutax Init **************************************/

         ret = pthread_mutex_init(&infra->wt_lock, NULL);
	 if(ret != 0)
	 {
		perror("pthread_mutex_init");
                free(infra->pipesFds);
                free(infra->fifoName);
                shmdt(&infra->shmid);
                ret = shmctl(infra->shmid,IPC_RMID,shmds);
                if(ret == -1)
                        printf("%s: shmctl() failed\n",__func__);
                ret = msgctl(infra->msgid,IPC_RMID,msgds);
                if(ret == -1)
                        printf("%s: msgctl() failed\n",__func__);
                ret = semctl(infra->semid,4,IPC_RMID);
                if(ret == -1)      
	      		printf("%s: shmctl() failed\n",__func__);
		ret = msgctl(infra->msgid_sv,IPC_RMID,msgds);
		if(ret == -1)
			printf("%s: msgctl() failed\n",__func__);
       		sem_close(&sem);
		free(infra);
	      	(*fptr[0])((void*)"failure");
	
	}
	printf("%s: Thread Mutax Successfully created\n",__func__);		

	/***************************************************************************************/


	system("ipcs");
	
	printf("%s:End\n",__func__);
	return (void*)infra;
}
