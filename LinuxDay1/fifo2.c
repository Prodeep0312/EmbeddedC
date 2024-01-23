#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{

int fd1,fd2;
char rbuf[50],wbuf[50];

fd1=open("f1",O_RDONLY);
fd2=open("f2",O_WRONLY);

while(1)
{
read(fd1,rbuf,50);
printf("%s",rbuf);

fgets(wbuf,50,stdin);
write(fd2,wbuf,strlen(wbuf)+1);


}



}

