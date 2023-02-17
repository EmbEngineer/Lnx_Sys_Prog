#include "../../Common/headers.h"
#include "header.h"
#include "../../Common/dataStruct.h"
#include "declaration.h"

void* exitFunc(void* arg)
{
  printf("%s : Begin\n",__func__);

  if(strncmp((char*)arg,"success",7) == 0 )
    exit(EXIT_SUCCESS);
  if(strncmp((char*)arg,"failure",7) == 0 )
    exit(EXIT_FAILURE);
  
  printf("%s : End\n",__func__);
  return 0;
}    

