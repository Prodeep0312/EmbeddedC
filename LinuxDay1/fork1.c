#include<unistd.h>
#include<stdio.h>

int main()

{
	int i;
	printf("Before Fork\n");
	i=fork();
	printf("After Fork\n");
	printf("End\n");
	printf("Bye\n");
	printf("%d\n",i);
	
	while(1);
	//this is needed so that process remains under execution and we can do ps


}
