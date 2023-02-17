#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/sem.h>

int main()
{
        int k_key;
	sleep(2);
	k_key = semget((key_t)124, 3, 0666|IPC_CREAT);
	if(k_key == -1)
	{
		perror("semget");
		exit(EXIT_FAILURE);
	}
	system("ipcs");
	return 0;
}
