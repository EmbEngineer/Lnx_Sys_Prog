#include "headers.h"
#include "declarations.h"

void* create_pipe(void* arg)
{
    int *pipe_fd, ret; 
    printf("Begin: %s\n",__func__ );
    pipe_fd = (int *)malloc(sizeof(int)*2);
    if(pipe_fd == NULL)
    {
         perror("malloc");
         (*fptr[0])((void*)"Failure");
    }
    ret = pipe(pipe_fd);	    
    if( ret == -1 )
    {
         perror("pipe");
         (*fptr[0])((void*)"Failure");
    }
    printf("End: %s\n",__func__);
    return (void *)pipe_fd;
}
