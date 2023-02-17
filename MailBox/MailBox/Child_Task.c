#include "headers.h"
#include "declarations.h"

void* child_task(void* arg)
{
      int fd;
      char c_fd[4];      
      printf("Begin: %s\n",__func__ );
      fd = *((int *)arg);
      printf("fd for child_task: %d\n",fd);
      sprintf(c_fd, "%d", fd);
      execl("../App/app", "app" , c_fd , NULL); 
      
      printf("End: %s\n",__func__);
      return NULL;
}
