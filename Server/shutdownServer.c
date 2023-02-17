#include"../Common/headers.h"
#include"headers.h"
#include"../Common/dataStruct.h"
#include"declaration.h"
void* shutdownServer(void* arg) 
{
	Infra *infra;
	struct shmid_ds *shmds;
	struct msqid_ds *msgds;
	int ret;
	printf("%s:BEGIN\n",__func__);
	
	infra = (Infra*)arg;
	

//      unlink(infra->fifoName);
//      system("unlink infra->fifoName");
	system("unlink servfifo");

	ret = msgctl(infra->msgid,IPC_RMID,msgds);
	if(ret == -1)
	{
		perror("msgctl");
	}

	
	close(infra->pipesFds[0]);
	close(infra->pipesFds[1]);

	free(infra->pipesFds);	
	free(infra->fifoName);
	
	shmdt(&infra->shmid);
	shmctl(infra->shmid,IPC_RMID,shmds);

	ret = msgctl(infra->msgid,IPC_RMID,0);
        if(ret == -1)
        	printf("%s: msgctl() failed\n",__func__);
	
	ret = msgctl(infra->msgid_sv,IPC_RMID,0);
        if(ret == -1)
        	printf("%s: msgctl() failed\n",__func__);
	
	shmdt(&smvt_key);
	shmctl(smvt_key,IPC_RMID,shmds);
	
	pthread_mutex_destroy(&infra->wt_lock);

        close(infra->fifo_fd);

	system("ipcs");

	(*fptr[0])((void*)"success");	

	printf("%s:END  \n",__func__);

return 0;
}
