#include "headers.h"
#include "declarations.h"

void* parent_task(void* arg)
{
    int wt, wt_fd, len; 
    pid_t id;
    printf("Begin: %s\n",__func__ );
    wt_fd =*((int *)arg+1);
    printf("write pipe FD at parent Task %d\n", wt_fd);
    printf("Now at sleep...........\n");
    sleep(10);
    len = write(wt_fd, "Aman Kumar Pandey", sizeof("Aman Kumar Pandey"));
    printf("nuber of byte written in pipe %d\n", len);
    id = wait(&wt);
    printf("End: %s\n",__func__);
    return NULL;
}
