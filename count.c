#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <fcntl.h>
#define buf 10
void sig_usr (int signo)
{
/*	sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigprocmask(SIG_BLOCK,&sigset, NULL);
	
	*/printf("%d\n",getpid());

//	longjmp(jumpbuffer,1);
}

int main(int argc, char **argv)
{	int fd;
	int count = 0;
	char buff[buf];
	struct sigaction usrsig;
	usrsig.sa_handler =sig_usr;
	sigemptyset(&usrsig.sa_mask);
	usrsig.sa_flags=0;
	sigaction(SIGUSR1,&usrsig,0);
	if(!(argv[1]>0))
		printf("insert positive integer");
	fd = open(argv[2],O_RDWR|O_CREAT|O_TRUNC);
	pwrite(fd,"0",3,0);
	read(fd,buff,10);
	printf("initial%s\n",buff);
	
//	jmp_buf jumpbuffer;
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
			next = granmaduh;	
			sleep(10);
		}
	}
	//setjmp(jumpbuffer);
	printf("%s",buff);
	while(1)		
	{
		//write(fd,buff[0],sizeof(buf));
		sleep(1);
		kill(next, SIGUSR1);
		printf("%s",buff);
		pause();
		sleep(1);
		
	}
//	while(1)
//	{}

	
	}
