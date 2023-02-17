#include "headers.h"
#include "declarations.h"

void* exit_func(void *arg)
{
       printf("Begin: %s\n",__func__ );
     
       if(strncmp((char*)arg, "Success", sizeof("SUCCESS")) == 0)
          exit(EXIT_SUCCESS);
       else if(strncmp((char*)arg, "Failure", sizeof("Failure")) == 0)
           exit(EXIT_FAILURE);
   
       printf("End: %s\n",__func__);
     return NULL;
}

