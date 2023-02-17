#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>


typedef struct MSG_BLOCK
{
	long msg_type;
	char msg[11];
}Msg_Block;

int main()
{
	int ret, MqId;
	Msg_Block msg_block;
	struct msqid_ds mq_buf;

        MqId = msgget((key_t)12, IPC_CREAT|0666);
	if(MqId == -1)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}

        ret = msgctl(MqId, IPC_STAT, &mq_buf);
	if(ret == -1)
	{
		perror("msgget: IPC_STAT");
		exit(EXIT_FAILURE);
	}
        
        ret = msgctl(MqId, IPC_SET, &mq_buf);
	if(ret == -1)
	{
		perror("msgget: IPC_STAT");
		exit(EXIT_FAILURE);
	}

        msg_block.msg_type = 10;
	strcpy(msg_block.msg ,"AmanPandey");

        ret = msgsnd(MqId, &msg_block, sizeof(msg_block.msg), 0);
	if(ret == -1)
	{
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}

//      Delte at Reader End
/*      ret = msgctl(MqId, IPC_RMID, &mq_buf);
	if(ret == -1)
	{
		perror("msgget: IPC_RMID");
		exit(EXIT_FAILURE);
	}
*/
	return 0;
}
