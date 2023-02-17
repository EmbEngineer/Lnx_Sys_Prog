#include"../Common/headers.h"
#include"headers.h"
#include"../Common/dataStruct.h"
#include"declaration.h"
void shutdownHandler(int sig, siginfo_t* si,void* arg) 
{

	printf("%s:BEGIN\n",__func__);
	
	flag = 1;

	printf("%s:END  \n",__func__);

	return ;
}
