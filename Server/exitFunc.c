#include"../Common/headers.h"
#include"declaration.h"

void* exitFunc(void* arg)
{
	printf("%s %s Ppid: %d Pid %d:Begin\n",__FILE__,__func__,getppid(),getpid());

	if(strncmp((char*)arg,"success",7))
		exit(EXIT_SUCCESS);
	if(strncmp((char*)arg,"failure",7))
		exit(EXIT_FAILURE);

	printf("%s %s Ppid: %d Pid %d:End\n",__FILE__,__func__,getppid(),getpid());

	return 0;
}
