#include "headers.h"
#include "declarations.h"

int main(int argc , char *argv[])
{
    int *ret, len;
    char buff[128] = {'\0'};
    printf("Reader Begin: %s\n",__func__ );
    init_func(NULL);
    ret = (int *)malloc(sizeof(int));
    if(ret == NULL)
    {
        perror("malloc");
        (*fptr[0])((void*)"Failure");
    }
    *ret = atoi(argv[1]);
    printf("Waiting for read.......now at sleep\n");
//    sleep(10);
    printf("Read Fd at Reader %d\n", *ret);
    len = read(*ret , buff , 128);
    printf("number of byte read %d and string is %s \n", len , buff);
    printf("Reader End: %s\n",__func__ );
    return 0;
}

