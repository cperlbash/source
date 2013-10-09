#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int dup3(int,int);
int main()
{
      int fd,fd3;
      if((fd=open("et",O_RDONLY))<0)
	    err_sys("open error");
      fd3=dup3(fd,18);
      printf("%d\n%d\n",fd,fd3);
      printf("%d\n", dup(fd));
      exit(0);
}
int dup3(int fd1,int fd2)
{
      int fd,fd3;
      if((fd=dup(fd1))==fd2)
	    return fd;
      else
	    if(fd<0)
		  return -1;
	    else
	    {
		  fd3=dup3(fd1,fd2);
		  close(fd);
	    }
      return fd3;
}


