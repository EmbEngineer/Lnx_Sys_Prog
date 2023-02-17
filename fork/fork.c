#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main()
{
	int  i, n, ret, wret;

	ret = fork();

	printf("Begin: Pid :- %d PPid :- %d\n",getpid(),getppid()); 
        switch(ret)
	{
		case -1:
			perror("fork");
			break;
		case 0:
			printf("ret :- %d Pid :- %d PPid :- %d\n",ret,getpid(),getppid()); 
                        n = 30;
			break;
		default:
			printf("ret :- %d Pid :- %d PPid :- %d\n",ret,getpid(),getppid()); 
		        n = 15;
		 	break;
	}

	for(i =0; i<n; i++)
	{		
		printf("Loop: Pid :- %d PPid :- %d\n",getpid(),getppid()); 
	        sleep(1);
	}	

	if(ret)
	{
		wait(&wret);      
		if(WIFEXITED(wret))
		{
			printf("Pid :- %d PPid :- %d child Terminated Normaly with Exit code %d\n",getpid(),getppid(),WEXITSTATUS(wret)); 
		}
	}
	printf("End: Pid :- %d PPid :- %d\n",getpid(),getppid()); 

	exit(n);

	return 0;
}
