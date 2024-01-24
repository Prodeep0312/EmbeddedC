#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int val1,val2,val3;

void* myfun1(int *maxval)
{
int count=0;
while(count<*maxval)
{
printf("In fun..............1\n");

printf("COUNT:%d\n",count);
count++;
usleep(200000);

}

val1=*maxval * *maxval;
return &val1;

}


void* myfun2(int *maxval)
{
int count=0;
while(count<*maxval)
{
printf("In fun..............2\n");

printf("COUNT:%d\n",count);
count++;
usleep(200000);

}
val2=*maxval * *maxval;
return &val2;

}

void* myfun3(int *maxval)
{
int count=0;
while(count<*maxval)
{
printf("In fun..................3\n");

printf("COUNT:%d\n",count);
count++;
usleep(200000);

}
val3=*maxval * *maxval;
return &val3;


}

int main()
{
	pthread_t tid1,tid2,tid3;
	
	int num1=50,num2=30,num3=40;
	
	pthread_create(&tid1,NULL,(void *)myfun1,&num1);
	//4th para ->if myfun1 took any arg
	
	pthread_create(&tid2,NULL,(void *)myfun2,&num2);
	pthread_create(&tid3,NULL,(void *)myfun3,&num3);

	//main th needs to wait for t1,t2,t3
	
	int *r1,*r2,*r3;

	pthread_join(tid1,(void **)&r1);
	pthread_join(tid2,(void **)&r2);
	pthread_join(tid3,(void **)&r3);
	printf("rval1::%d\n",*r1);
	printf("rval2::%d\n",*r2);
	printf("rval3::%d\n",*r3);

	printf("Main thread completed execution");


	


}
