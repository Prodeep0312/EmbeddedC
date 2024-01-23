#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{

int x[2];

pipe(x);

int i=fork();

if(i==0)

{

printf("In child process\n");
write(x[1],"HELLO DELHI",12);
printf("Child writes..\n");
}

else{

char buff[20];

printf("In parent process\n");
read(x[0],buff,12);
printf("Data read from pipe:%s\n",buff);

}


}
