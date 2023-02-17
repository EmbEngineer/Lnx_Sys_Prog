#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/wait.h>
#include "declaration.h"
int main()
{
        int running = 1;
	void *Shared_Memory = (void *)0;
	User_Msg *user_msg;
        int SmId, ret;

	SmId = shmget((key_t)123, sizeof(User_Msg), 0666|IPC_CREAT);
	if(SmId == -1)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}

	Shared_Memory = shmat(SmId, (void *)0, 0);
	if( Shared_Memory == (void *)-1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	user_msg = (User_Msg *)Shared_Memory;

	while(running)
	{
		if(user_msg->data_available)
		{
			printf("Received Msg :- %s\n",user_msg->msg);
			user_msg->data_available = 0;
		}
		
		if(strncmp(user_msg->msg, "End", 3) == 0)
			running = 0;
		
		sleep(1);
	}

	return 0;
}
