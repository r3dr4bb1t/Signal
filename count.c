#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <fcntl.h>
void sig_usr (int signo)
{
	printf("%d\n",getpid());
//	longjmp(jumpbuffer,1);
}

int main(int argc, char **argv)
{	int fd;
	fd = open(argv[2],O_RDWR|O_CREAT|O_TRUNC);
	write(fd,"0",1);
	signal(SIGUSR1, sig_usr);
	jmp_buf jumpbuffer;
	pid_t next,ppid,granmaduh;
	granmaduh = getpid();
	if ((next = fork()) <0 )
	{ 
			fprintf(stderr, "fork() error");
			exit(1);
	 }
	else if (next == 0  )
	{
		
		next = fork();
		if (next >0)
		{
			sleep(6);
		}
		else 
		{
			signal(SIGUSR1, sig_usr);
			next = granmaduh;	
			sleep(10);
		}
	}
	sleep(2);
	printf("%d\n",next);
	//setjmp(jumpbuffer);


	kill(next, SIGUSR1);
	exit(1);
	
}
	
