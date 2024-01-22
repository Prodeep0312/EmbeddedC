#include<unistd.h>
#include<stdio.h>

int main()

{
	int i;
	
	i=fork();
	
	if(i==0)
	{
	
	printf("In child process\n");
	printf("In Child Process , Child Process pid:%d\n",getpid());
	printf("In Child Process,Parent Process pid:%d\n",getppid());
	}
	else
	{
	
	printf("In parent process\n");
	printf("In parent process,Parent Process pid:%d\n",getpid());
	printf("In parent process, Child Process pid:%d\n",i);
	}
	
	
	while(1);
	//this is needed so that process remains under execution and we can do ps


}
