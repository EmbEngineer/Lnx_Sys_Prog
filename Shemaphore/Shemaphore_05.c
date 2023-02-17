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
struct sembuf sem_buf;

int wait_operation(void);
int signal_operation(void);

int main()
{
	int i;
	union semun sem_union[4];
	sleep(3);
	k_key = semget((key_t)10, 4, 0666|IPC_CREAT);
        if(k_key == -1)
	{
		perror("semget");
		exit(EXIT_FAILURE);
	}		
        system("ipcs");
	for(i = 0; i<4 ; i++)
	{
             sem_union[i].val = 1;             // shemaphore variable
             if(semctl(k_key, i, SETVAL, sem_union[i]) <0)
             {
		     perror("semctl");
		     exit(EXIT_FAILURE);
	     }
	}

        for( i =0; i<10; i++)
	{
  	      	
                if(wait_operation())
		{	
      	               printf("Enter in the Critical Region of %s and pid is %d\n",__func__, getpid());
                       sleep(5);
                }
		if(signal_operation() == -1)
			printf("failed to signal Operation\n");
        }

	for(i = 0; i<1 ; i++)
	{
             if(semctl(k_key, i, IPC_RMID) < 0)
             {
		     perror("semctl");
		     exit(EXIT_FAILURE);
	     }
	}
        system("ipcs");
        return 0;
}

int wait_operation(void)
{
	sem_buf.sem_num = 0;
	sem_buf.sem_op = -1;                   // decrement shemaphore variable
	sem_buf.sem_flg = SEM_UNDO;
       	if(semop(k_key, &sem_buf, 1) == -1)
        {
	        perror("semop");
                return 0;
	      //exit(EXIT_FAILURE);
	}
      return 1;	
}

int signal_operation(void)
{
 
     sem_buf.sem_num = 0;
     sem_buf.sem_op = 1;                     // increment shemaphore variable
     sem_buf.sem_flg = SEM_UNDO;
     if(semop(k_key, &sem_buf, 1) == -1)
     {
          perror("semop");
          return 0;
	//exit(EXIT_FAILURE);
     }
     return 1;
}
