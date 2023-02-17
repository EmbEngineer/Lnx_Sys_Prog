#include "headers.h"
#include "declarations.h"

void* open_file(void* arg)
{
      int *fd;
      printf("Begin: %s\n",__func__ );
      fd = (int *)malloc(sizeof(int));
      if(fd == NULL)
      {
	      perror("malloc");
	      (*fptr[0])((void*)"Failure");
      }	      
      if(strncmp((char *)arg, "read|write" , sizeof("read|write")) == 0)
      {
	       *fd = open("MyFile" , O_RDWR|O_CREAT );
               if(*fd == -1) 
	       {
		       perror("open");
		       free(fd);
	               (*fptr[0])((void*)"Failure");
	       }   
      }
      printf("End: %s\n",__func__ );
    return (void *)fd;
}
