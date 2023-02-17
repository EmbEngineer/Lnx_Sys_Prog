#include"../Common/headers.h"
#include"../Common/dataStruct.h"
#include<sys/types.h>
#include<sys/msg.h>

int main(int argc,char* argv[])
{
	int fd, mqId, ret;
	Request_Mq req_mq;
	Result res;

	printf("%s: BEGIN\n",__FILE__);

	req_mq.clientpid  = getpid();
	req_mq.req.op1 = 33;
	req_mq.req.op2 = 22;
	req_mq.req.opr = '+';

	fd = open("servfifo" , O_WRONLY);
	if(fd == -1)
	{
                perror("open");
                exit(EXIT_FAILURE);
	}
	
	ret = write(fd,&req_mq ,sizeof(Request_Mq));
	if(ret == -1)
	{
                perror("write");
                exit(EXIT_FAILURE);
	}

	close(fd);
	
	mqId = msgget((key_t)4, IPC_CREAT|0666);
	if(mqId == -1)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	ret = msgrcv(mqId, &res, sizeof(int), req_mq.clientpid , 0);
	if(ret == 0)
	{
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	
	printf("%s :-------------------------------------> Final Result :- %d\n",__func__,res.result);
	
	printf("%s: END\n",__FILE__);
	return 0;
}
