#include "headers.h"
#include "declarations.h"

int main(int argc , char *argv[])
{
    int *ret;
    printf("App Begin: %s\n",__func__ );
    init_func(NULL);
    ret = (int *)malloc(sizeof(int));
    if(ret == NULL)
    {
        perror("malloc");
        (*fptr[0])((void*)"Failure");
    }
    *ret = atoi(argv[1]);
    printf("1 - %d\n", *ret);
    (*fptr[1])((void *)ret);
    printf("App End: %s\n",__func__ );
    return 0;
}

