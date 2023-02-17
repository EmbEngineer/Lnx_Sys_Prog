#ifndef FIFONAME
#define FIFONAME "servfifo"
#endif

#ifndef SMKEY_VT
#define SMKEY_VT 11
#endif

#ifndef SMKEY
#define SMKEY 10
#endif

#ifndef MQKEY
#define MQKEY  4
#endif

#ifndef SEMKEY
#define SEMKEY 1000
#endif

#ifndef MQKEY_SV
#define MQKEY_SV  5
#endif

#ifndef ShKEY_VPT
#define ShKEY_VPT 6
#endif

extern int smvt_key;
extern void *smvt_ptr;

/* arg for semctl system calls. */
union semun {
        int val;                        /* value for SETVAL */
        struct semid_ds *buf;    /* buffer for IPC_STAT & IPC_SET */
        unsigned short *array;   /* array for GETALL & SETALL */
        struct seminfo *__buf;   /* buffer for IPC_INFO */
        void *__pad;
};


typedef struct request
{
	int op1;
	int op2;
	char opr;
}Request;

typedef struct REQUEST_MQ
{
        long clientpid;
	struct request req;
}Request_Mq;

typedef struct infra
{
	int *pipesFds;//pipe file discriptor
	char *fifoName;//for fifo
	int shmid;
	void *shrdMem;
	int msgid;
	int msgid_sv;
        int semid;	//for semaphores
        int fifo_fd;
	pthread_mutex_t wt_lock;
}Infra;

typedef struct
{
	long clientPid;
	int result;
}Result;


