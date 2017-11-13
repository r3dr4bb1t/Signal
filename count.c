#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define buf 128
int main (int argc, char** argv)
{	
	int fd;
	char buff[buf]={0} ;

	int iszeroOrnewfile=1;
	int iszero=0;
	if(!(argv[0]>0))
		printf("insert positive integer");
	fd = open("./sample.txt",O_RDWR|O_CREAT|O_TRUNC);
	write(fd, "0",strlen("0");
	pid_t child[3];

	signal(SIGUSR1, (
/*	pread ( fd,buff,buf,0);
	for (int i=0;i<buf;i++)
	{	
		if((0 != buff[i])||('0'!=buff[i]) )
				iszeroOrnewfile = 0;		
		if('0' == buff [i])
			 iszero = 1;
		
	}
	if (iszeroOrnewfile == 1 )
	{ 
		if (iszero !=1)
		write(fd, "0",strlen("0"));
	}
	else if(iszeroOrnewfile ==0)
	{
		truncate ("./sample.txt" , 0);
		write(fd, "0",strlen("0"));
	}*/
	
}

