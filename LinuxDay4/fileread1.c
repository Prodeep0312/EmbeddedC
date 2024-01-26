#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
	int fd;
	char buff[50]={0};
	// to avoid garbage values


	fd=open("file1",O_RDONLY);
	printf("fd=%d\n",fd);

	//because we know 16 chars are there in files
	read(fd,buff,16);
	printf("buf::%s \n",buff);
	close(fd);


}
