#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{

int x[2],y[2];

pipe(x);
pipe(y);

int i=fork();

if(i==0)

{
char data[20];
printf("In child process\n");
read(x[0],data,15);
printf("Data read from child:%s\n",data);
write(y[1],"HELLO MY PARENT",16);

}

else{

char buff[20];

printf("In parent process\n");
write(x[1],"HELLO MY CHILD",15);
read(y[0],buff,16);
printf("Data read from parent:%s\n",buff);

}


}
