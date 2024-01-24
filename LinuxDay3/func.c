#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void myfun1()
{
int count=0;
while(count<50)
{
printf("In fun..........1\n");
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
printf("In fun.............2\n");
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
printf("In fun.............3\n");
printf("COUNT:%d\n",count);
count++;
usleep(200000);

}

}

int main()
{
	myfun1();
	myfun2();
	myfun3();

	


}
