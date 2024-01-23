#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{

int fd1,fd2;
char rbuf[50],wbuf[50];

fd1=open("f1",O_WRONLY);
fd2=open("f2",O_RDONLY);

while(1)
{

fgets(wbuf,50,stdin);
write(fd1,wbuf,strlen(wbuf)+1);


read(fd2,rbuf,50);
printf("%s",rbuf);
}



}

