#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void myfun1()
{
int count=0;
while(count<50)
{
printf("In fun..............1\n");
printf("In fun1 ,process id::%d  thread id=%lu\n",getpid(),pthread_self());
printf("COUNT:%d\n",count);
count++;
usleep(200000);

}

}


void myfun2()
{
int count=0;
while(count<40)
{
printf("In fun..............2\n");
printf("In fun2 ,process id::%d  thread id=%lu\n",getpid(),pthread_self());
printf("COUNT:%d\n",count);
count++;
usleep(200000);

}

}

void myfun3()
{
int count=0;
while(count<30)
{
printf("In fun..................3\n");
printf("In fun3 ,process id::%d  thread id=%lu\n",getpid(),pthread_self());
printf("COUNT:%d\n",count);
count++;
usleep(200000);

}

}

int main()
{
	pthread_t tid1,tid2,tid3;
	
	pthread_create(&tid1,NULL,(void *)myfun1,NULL);
	//4th para ->if myfun1 took any arg
	
	pthread_create(&tid2,NULL,(void *)myfun2,NULL);
	pthread_create(&tid3,NULL,(void *)myfun3,NULL);

	//main th needs to wait for t1,t2,t3

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);

	printf("Main thread completed execution");


	


}
