#include "headers.h"
#include "declarations.h"

int main(void)
{
    int ret, *fd;
    printf("Begin: %s\n",__func__ );
    init_func(NULL);
    fd = (*fptr[3])((void *)"read|write");
    ret = write(*fd , "Aman is a boy" , sizeof("Aman is a boy"));
    lseek( *fd , SEEK_SET , 0);
    printf("number of Bytes write in file  %d\n", ret);
    ret = fork();
    switch(ret)
    {
	case -1:    
              perror("fork");
	      (*fptr[0])((void*)"Failure");                
	case 0:
              (*fptr[2])((void*)fd);           //  parent Task
	default:
             (*fptr[1])((void*)NULL);           //  parent Task
    }  
    printf("End: %s\n",__func__ );
    return 0;
}

