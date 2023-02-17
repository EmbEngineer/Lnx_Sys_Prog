typedef struct Request
{
  pid_t pid;
  char opr;
  int opr1;
  int opr2;
}request;

typedef struct Proc
{
   int *pipe;
   request *r;
}proc;
