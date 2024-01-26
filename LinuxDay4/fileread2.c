//read char by char...read returns 0 on reaching eof

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
	int fd;
	char buff;


	fd=open("file1",O_RDONLY);
	printf("fd=%d\n",fd);

	while(1)
	{
		if(read(fd,&buff,1) == 0)
			break;
		else
			printf("%c",buff);
		
	}
	
	close(fd);


}

