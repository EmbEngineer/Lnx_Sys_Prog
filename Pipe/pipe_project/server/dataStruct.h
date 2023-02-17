typedef struct request
{
  pid_t pid;
  char opr;
  int opr1;
  int opr2;
}request;

typedef struct proc
{
   int *pipe;
   request *r;
}proc;
