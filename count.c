#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>

int N, fd;

pid_t pid[3];
pid_t next_pid;
clock_t begin_time, end_time;

void wake_next();
void exit_all();
void my_sleep();

int main(int argc, char ** argv)
{
   if(argc < 3) {
       printf("Need N, filepath\n");
       return -1;
   }

   if(signal(SIGUSR1, wake_next) == SIG_ERR) {
       fprintf(stderr, "Failed to set sigusr1 handler\n");
       return -1;
   }
   if(signal(SIGQUIT, exit_all) == SIG_ERR) {
       fprintf(stderr, "Failed to set sigquit handler\n");
       return -1;
   }

   N = atoi(argv[1]);
   if((fd = open(argv[2], O_RDWR | O_CREAT, 0644)) == 0) {
       fprintf(stderr, "Failed to open file");
       return -1;
   }

   pwrite(fd, "0            ", 14, 0);

   pid[0] = getpid();
   if((pid[1] = fork()) == 0) {
       if((pid[2] = fork()) == 0) {
           next_pid = pid[0];
           begin_time = clock();
           kill(next_pid, SIGUSR1);
           my_sleep();
       } else {
           next_pid = pid[2];
           my_sleep();
       }
   } else {
       next_pid = pid[1];
       my_sleep();
   }

   return 0;
}

void wake_next()
{
   char buffer[256];

   pread(fd, buffer, 14, 0);
   int now = atoi(buffer);

   if(now >= N) {
       end_time = clock();
       printf("Time: %f\n", (double)(end_time - begin_time) / CLOCKS_PER_SEC);
       close(fd);
       kill(pid[0], SIGQUIT);
       exit(1);
   }

   sprintf(buffer, "%d                ", now + 1);
   pwrite(fd, buffer, 14, 0);

   kill(next_pid, SIGUSR1);
}

void exit_all() {
   exit(0);
}

void my_sleep()
{
   while(1) {
       sleep(10);
   }
}
