/**
 *      file    :  exitFunc.c
 *      author  :  deepak_jangra
 *      created :  2021 Apr 28 08:35:23  IST
 *      lastMod :  Wednesday 28 April 2021 08:35:23 AM IST
 **/

#include"header.h"
#include"declaration.h"

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

