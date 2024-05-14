#include<stdio.h>
#include<unistd.h>

int main()
{

  int pid;
  pid = fork();

  int oddSum = 0 , evenSum = 0 , n = 20;

  if(pid == 0)
  {
    for(int i=1;i<=n;i++)
       if(i%2!=0)oddSum+=i;
  }
  else if(pid > 0)
  {
    for(int i=1;i<=n;i++)
       if(i%2==0)evenSum+=i;
  }
  if(pid == 0)
  printf("The pid %d and parent %d and sum %d\n",getpid(),getppid(),oddSum);
  else
  printf("The pid %d and parent %d sum %d\n",getpid(),getppid(),evenSum);
}