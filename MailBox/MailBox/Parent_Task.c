#include "headers.h"
#include "declarations.h"

void* parent_task(void* arg)
{
    int wt; 
    pid_t id;
    printf("Begin: %s\n",__func__ );
    id = wait(&wt);
    printf("End: %s\n",__func__);
    return NULL;
}
