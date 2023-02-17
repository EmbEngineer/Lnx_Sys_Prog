#include "headers.h"
#include "declarations.h"

void* child_task(void* arg)
{
      int rd_fd;
      char c_fd[4];      
      printf("Begin: %s\n",__func__ );
      rd_fd =*((int *)(arg));
      printf("Read pipe FD at child Task %d\n", rd_fd);
      sprintf(c_fd, "%d", rd_fd);
      execl("../Reader/reader", "reader" , c_fd ,"Aman", NULL); 
      printf("End: %s\n",__func__);
      return NULL;
}
