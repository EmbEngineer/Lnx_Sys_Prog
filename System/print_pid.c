#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	printf("Begine: Pid :- %d PPid :- %d Function Name :- %s File Name :- %s\n",getpid(),getppid(),__func__,__FILE__);
	

	sleep(5);

	printf("End: Pid :- %d PPid :- %d Function Name :- %s File Name :- %s\n",getpid(),getppid(),__func__,__FILE__);
	return 0;
}
