#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int k_key;
/* arg for semctl system calls. */
union semun {
        int val;                        /* value for SETVAL */
        struct semid_ds *buf;    /* buffer for IPC_STAT & IPC_SET */
        unsigned short *array;   /* array for GETALL & SETALL */
        struct seminfo *__buf;   /* buffer for IPC_INFO */
        void *__pad;
};

int main()
{
	int i;
	union semun sem_union[4];
	k_key = semget((key_t)123, 4, 0666|IPC_CREAT);
        if(k_key == -1)
	{
		perror("semget");
		exit(EXIT_FAILURE);
	}		
        system("ipcs");
	for(i = 0; i<4 ; i++)
	{
             sem_union[i].val = 1;
             if(semctl(k_key, i, SETVAL, sem_union[i]) <0)
             {
		     perror("semctl");
		     exit(EXIT_FAILURE);
	     }
	}	
        return 0;
}
