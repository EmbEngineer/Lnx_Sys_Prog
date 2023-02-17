#include "headers.h"
#include "declarations.h"

int main(void)
{
    int ret, *fd;
    printf("Begin: %s\n",__func__ );
    init_func(NULL);
    fd = (*fptr[3])(NULL);
    printf(" Read fd %d\n", *fd);
    printf(" Write fd %d\n", *(fd+1));
    ret = fork();
    switch(ret)
    {
	case -1:    
              perror("fork");
	      (*fptr[0])((void*)"Failure");                
	case 0:
              (*fptr[2])((void*)fd);           //  parent Task
	default:
             (*fptr[1])((void*)fd);           //  parent Task
    }  
    printf("End: %s\n",__func__ );
    return 0;
}

