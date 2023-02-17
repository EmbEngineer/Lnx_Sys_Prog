#include "../../Common/headers.h"
#include "header.h"
#include "../../Common/dataStruct.h"
#include "declaration.h"

int main(int argc, char* argv[])
{
 	int ret, *fd, shmid; 
 	pthread_t thid;

 	printf("ADDER Begin : %s\n",__func__);

        init();

	fd = (int *)malloc(sizeof(int));
	if(!fd)
	{
                perror("malloc");
                (*fptr[0])((void*)"failure");
	}

 	*fd = atoi(argv[1]);
  	printf("%s : FD :- %d\n",__func__,*fd);

        smvt_key = shmget((key_t)SMKEY_VT,sizeof(sem_t),IPC_CREAT|0666);
        if(smvt_key == -1)
        {
                perror("shmget");
                (*fptr[0])((void*)"failure");
        }
	
        smvt_ptr = shmat(smvt_key, 0, 0);
        if(!smvt_ptr)
        {
                perror("shmat");
                (*fptr[0])((void*)"failure");
        }

        shkey_vpt = shmget((key_t)SMKEY,sizeof(Result),IPC_CREAT|0666);
        if(shmid == -1)
        {
                perror("shmget");
                (*fptr[0])((void*)"failure");
        }

        shmptr = shmat(shkey_vpt, 0, 0);
        if(!shmptr)
        {
                perror("shmat");
                (*fptr[0])((void*)"failure");
        }

	shkey_vpt = semget((key_t)ShKEY_VPT, 1, 0666|IPC_CREAT);
        if(shkey_vpt == -1)
        {
                perror("semget");
                (*fptr[0])((void*)"failure");
        }

	sem_union[0].val = 1;             // shemaphore variable
        
	if(semctl(shkey_vpt, 0, SETVAL, sem_union[0]) <0)
        {
                perror("semctl");
                (*fptr[0])((void*)"failure");
        }

	ret = pthread_create(&thid, NULL, fptr[1], (void *)fd);
       	if(ret == -1)
  	{
		perror("pthread_creat");
	  	(*fptr[0])((void*)"failure");
  	}

        pthread_join(thid,NULL);
	
	printf("ADDER END : %s\n",__func__);
        return 0;
}    
