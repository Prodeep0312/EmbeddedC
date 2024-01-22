#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()

{	int a,b;
	int x[2];
	
	a=open("f1.txt",O_RDONLY);
	b=open("f2.txt",O_RDONLY);
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	
	pipe(x);
	
	printf("x[0]=%d\n",x[0]);
	printf("x[1]=%d\n",x[1]);
	
	
	
	
	while(1);
	//this is needed so that process remains under execution and we can do ps


}
