#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
	int fd;
	fd=open("file1",O_WRONLY);
	printf("fd=%d\n",fd);
	write(fd,"HELLO CARL ZEISS",16);
	close(fd);


}
