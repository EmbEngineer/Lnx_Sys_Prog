/**
 *      file    :  adder.c
 *      author  :  deepak_jangra
 *      created :  2021 Apr 30 10:43:59  IST
 *      lastMod :  Friday 30 April 2021 10:43:59 AM IST
 **/

#include"header.h"
#include"dataStruct.h"

int main(int argc, char* argv[])
{
  printf("%s : Begin\n",__func__);

  int wfd5 = atoi(argv[1]);
  int rfd6 = atoi(argv[2]);


  printf("WRITE FILE DISCRIPTOR %d\n", wfd5);
  printf("READ FILE DISCRIPTOR %d\n", rfd6);


  
  printf("%s : End\n",__func__);
  return 0;
}    

