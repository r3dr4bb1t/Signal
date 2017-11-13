#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void sig_fn (int);
struct sigaction act;
int main (int argc, char **argv)

{
	act.sa_handler = sig_fn;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);
	while (1)
	{
		printf("\n");
		sleep(1);
	}
	return 0;
}
void sig_fn (int signo) 
{
	printf("Ctrl-C is pressed. Try Again\n");
}
	


