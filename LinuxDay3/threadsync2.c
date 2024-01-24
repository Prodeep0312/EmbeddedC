#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;



void displayMulTable(int *num)
{	


	printf("Thread %d is trying to take lock\n",*num);
	//decrement by 1
	pthread_mutex_lock(&m1);
	printf("Thread %d takes lock\n",*num);

	printf("Multiplication Table of %d\n",*num);
	for(int i=1;i<=10;i++)
	{
		sleep(1);
		printf("%d x %d=%d\n",*num,i,*num*i);
		

	}
	printf("********************************");
	pthread_mutex_unlock(&m1);
	printf("Thread %d releases the  lock\n",*num);


}

int main()

{

	pthread_t t1,t2,t3;
	int num1=15,num2=6,num3=12;
	pthread_create(&t1,NULL,(void *)displayMulTable,&num1);
	pthread_create(&t2,NULL,(void *)displayMulTable,&num2);
	pthread_create(&t3,NULL,(void *)displayMulTable,&num3);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);

	//we will get mixed op of tables
	


}
