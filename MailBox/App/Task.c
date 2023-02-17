#include "headers.h"
#include "declarations.h"

void* task(void* arg)
{
    int fd,len;
    fd = *((int *)arg);
    char buf_len[128] = "\0";
    printf("Begin: %s\n",__func__ );
    printf("fd for task %d\n", fd);
    len = read(fd, buf_len , 128);
    printf("number of byte read %d and read string is \" %s \"\n", len , buf_len);
    printf("End: %s\n",__func__);
    return NULL;
}
