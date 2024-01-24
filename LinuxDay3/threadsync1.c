#include<stdio.h>
#include<pthread.h>
#include<unistd.h>



void displayMulTable(int *num)
{
	printf("Multiplication Table of %d\n",*num);
	for(int i=1;i<=10;i++)
	{

		printf("%d x %d=%d\n",*num,i,*num*i);
		sleep(1);

	}
	printf("********************************");

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
