#include <errno.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <fcntl.h>
#include <pthread.h>
#define buf 10

pthread_mutex_t lock;

void sig_usr (int signo)
{
	/*sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigprocmask(SIG_BLOCK,&sigset, NULL);

	sigwait(&sigset,&signo);*/
	printf("%d\n",getpid());
//	sigprocmask(SIG_UNBLOCK,&sigset,NULL);

//	longjmp(jumpbuffer,1);
}

int main(int argc, char **argv)
{	int fd;
	pthread_mutex_init(&lock,NULL);
	int count = 0;
	FILE *fp;
	int i;
	char buff[buf];
	struct sigaction usrsig;
	usrsig.sa_handler =sig_usr;
	sigemptyset(&usrsig.sa_mask);
	usrsig.sa_flags=0;
	sigaction(SIGUSR1,&usrsig,0);
	if(!(argv[1]>0))
		printf("insert positive integer");

	fd = open(argv[2],O_RDWR|O_CREAT|O_TRUNC);
	pwrite(fd,"0",1,0);

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
			sleep(2);
		}
		else 
		{
			next = granmaduh;	
			sleep(3);
		}
	sleep(1);
	}
	//setjmp(jumpbuffer);
	while(1)		
	{	int signo; 
		int status;
		sigset_t sigset;
		sigemptyset(&sigset);
		sigaddset(&sigset, SIGUSR1);
		sigprocmask(SIG_BLOCK,&sigset, NULL);	
		pthread_mutex_lock(&lock);
		if (i<argv[1])
		read(fd,buff,10);
//		printf("initial%c\n",buff[0]);
		i = atoi(buff);
 		++i;
		snprintf(buff,buf,"%d",i);
		fd = open(argv[2],O_RDWR|O_CREAT|O_TRUNC);
		write(fd,buff,1);
		kill(next, SIGUSR1);
		pause();	
		printf("%c\n",buff[0]);
		pthread_mutex_unlock(&lock);
		sleep(1);	
	}
//	while(1)
//	{}

	
}
