#include<stdio.h>   
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define SERVER_FILE_NAME  "./example_test_server"

typedef struct Data_To_Be_send
{
	pid_t pid;
        char buffer[50];
}data_to_be_send;

int main()
{
	int pipe_fd;
	int ret, buffer_len;
//	int server_open_mode = O_RDONLY|O_NONBLOCK;
	int server_open_mode = O_RDONLY;
	int client_open_mode = O_WRONLY;
	char buffer[50];
	data_to_be_send dtbs_S, dtbs_R;
 	printf("Begine : %s\n",__func__);
        memset(buffer, '\0' , sizeof(buffer));
        memset(dtbs_S.buffer, '\0' , sizeof(dtbs_S));
        memset(dtbs_R.buffer, '\0' , sizeof(dtbs_R));
	if(access(SERVER_FILE_NAME, F_OK) == -1)
	{
		ret = mkfifo(SERVER_FILE_NAME,0666);
		if(ret == -1)
		{
			printf("failed to open FIFO\n");
			exit(EXIT_FAILURE);
		}
		else
		 	printf("FIFO is Successfully created\n");

	}
        else
		 printf("FIFO is allready exsist\n");

        fflush(stdout);	
        buffer_len = sizeof(dtbs_R);
        pipe_fd = open(SERVER_FILE_NAME, server_open_mode);
        ret = read(pipe_fd ,&dtbs_R ,buffer_len);
        if(ret == -1)
        {
                printf("failed to read on FIFO\n");
                exit(EXIT_FAILURE);
        }
        printf("No of byte read %d\n", ret);
        printf("Received pid : %d\n",dtbs_R.pid);
        printf("Received Data : %s\n",dtbs_R.buffer);
        close(pipe_fd);

	pipe_fd = open(SERVER_FILE_NAME, client_open_mode);
	dtbs_S.pid = getpid();
	printf("Pid of client %d\n",dtbs_S.pid);
        printf("please enter the string\n");
	scanf("%s",(char *)&dtbs_S.buffer);
        buffer_len = sizeof(dtbs_S);
        ret = write(pipe_fd ,&dtbs_S ,buffer_len);
        if(ret == -1)
        {
                printf("failed to write on FIFO\n");
                exit(EXIT_FAILURE);
        }
	printf("No of byte write %d\n", ret);
	close(pipe_fd);
	printf("END : %s\n",__func__);
	return 0;
}

