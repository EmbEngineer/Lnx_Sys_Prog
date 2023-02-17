#include"../Common/headers.h"
#include"headers.h"
#include"../Common/dataStruct.h"
#include"declaration.h"
void* signalCheck(void* arg) 
{
	Infra *infra;
	printf("%s:BEGIN\n",__func__);
	infra = (Infra*)arg;
	while(1)
        {
		if(flag)
               	{
                       	(*fptr[2])((void*)infra);             //calling shutdownServer
                       	(*fptr[0])((void*)"success");         //calling exitFunc
               	}
	
        }

	printf("%s:END  \n",__func__);
	pthread_exit(NULL);

	return 0 ;
}
