#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{       
	int i, n;
        printf("%s: Begin Pid :- %d and PPid :- %d\n",__FILE__,getpid(),getppid());
        
	printf("%s: NO of Count :- %d\n",__func__,argc-1); 

	for( i= 1; i< argc; ++i)
	{
		printf("%s: %d Argument is  %s\n",__FILE__,i,argv[i]); 
	}
        
	n =25;
	for( i= 0; i<n ; ++i)
	{
        	printf("%s : %s: Exicuuting Pid :- %d and PPid :- %d\n",__FILE__, __func__,getpid(),getppid());
		sleep(1);
	}

	printf("%s:End Pid :- %d and PPid :- %d\n",__FILE__,getpid(),getppid());
        exit(n);
	return 0;
}  
