#include"../Common/headers.h"
#include"headers.h"
#include"../Common/dataStruct.h"
#include"declaration.h"

int main(int argc,char *argv[]) 
{
	int ret,thret;
	Infra *infra;
	struct sigaction act;
	pthread_t newthread,thid, thid_v;
	printf("%s:BEGIN\n",__func__);

	init();

	//signal(SIGINT, shutdownHandler);
	act.sa_handler = NULL;
	act.sa_sigaction = shutdownHandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;

	sigaction(SIGINT , &act ,NULL );

	infra = (Infra*)(*fptr[1])(0);   	//calling creat infra

/*
	infra->fifo_fd = open("servfifo",O_RDONLY);
        if(infra->fifo_fd == -1)
        {
                perror("open");
                (*fptr[0])((void*)"failure");
        }
*/
	// creating one thread to check flag continiously to shutdown
	ret = pthread_create(&newthread,NULL,fptr[3],(void*)infra);
	if(ret==-1)
	{
		perror("pthread_create");
		(*fptr[0])((void*)"failure");                         //calling exit function
	}

	ret = pthread_create(&thid_v,NULL,fptr[5],(void*)infra);
	if(ret==-1)
	{
		perror("pthread_create");
		(*fptr[0])((void*)"failure");                         //calling exit function
	}
	
	while(1)
	{
		if(sem_wait(&sem) == -1)
		{
			perror("sem_wait");
			(*fptr[0])((void*)"failure");//calling exit function
		}
	
		thret = pthread_create(&thid,NULL,fptr[4],(void*)infra);//calling process request
		if(thret==-1)
		{
			perror("pthread_create");
			(*fptr[0])((void*)"failure");//calling exit function
		}
	}

	printf("%s:END  \n",__func__);

	return 0;
}
