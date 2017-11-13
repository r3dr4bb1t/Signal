#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define buf 128


int main (int argc, char** argv)
{
    int fd;
    char buff[buf]={0} ;
    int iszeroOrnewfile=1;
    int iszero=0;
    int isFileCreated = 0;
    int len = 0;
    int i;
    if(!(argv[0]>0))
        printf("insert positive integer");
    fd = open("./sample.txt",O_RDWR);
    if(fd==-1 && errno==ENOENT)
    {
        //File dosen't exists
        isFileCreated = 1;
        fd = open("./sample.txt",O_RDWR|O_CREAT);
        write(fd, "0",strlen("0"));
    }
    else
    {
        len = pread ( fd,buff,buf,0);
        for (i=0;i<len;i++)
        {
            if((0 == buff[i]) || ('0' == buff[i]) )
            {
                iszero = 1;
                break;
            }
        }
        if(len==-1 || iszero)
        {
            truncate ("./sample.txt" , 0);
            write(fd, "0",strlen("0"));
        }
    }
    return 0;
}
