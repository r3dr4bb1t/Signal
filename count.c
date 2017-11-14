#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
void sig_usr1(int signo)
{	
	char a;
	sigset_t sigset, oldset;
	sigemptyset (&oldset);
	sigemptyset (&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigprocmask(SIG_BLOCK, &sigset, &oldset);
	
	fd =open("./sample.txt",O_RDWR);
	pread (fd, a, sizeof(a));
	if (argv[0]>a)
	{a ++;
	truncate ("./sample.txt", 0);
	write(fd, a, sizeof(a));
	}
}
int main (int argc, char** argv)
{	
	int fd;
	int num=0;
	struct sigaction usrsig ;
	if(!(argv[0]>0))
		printf("insert positive integer");
	fd = open("./sample.txt",O_RDWR|O_CREAT|O_TRUNC);
	write(fd, num ,sizeof(num);
	pid_t child[3];
					
	usrsig.sa_handler =sig_usr;  // Parent
	sigemptyset(&usrsig.sa_mask); 
 	usrsig1.sa_flags = 0;
	sigaction(SIGUSR1,&usrsig, 0);
	
	for ( i=0; i<3; i++)
	{
	 	child[i] = fork();
	 	if(child[i] == 0)
	 	break;
	}
	pid_t prev;
	if(i ==0)	prev = getppid();
	else 		prev = child[i-1];

	kill(pid_prev, SIGUSR1)
}

