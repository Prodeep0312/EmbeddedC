#include<stdio.h>
#include<stdlib.h>

void fun1()
{printf("1");
}

void fun2()
{printf("2");}


void fun3()
{printf("3");}


void fun4()
{printf("4\n");}

int funint(int n1, int n2)
{
return n1+n2;
}


int main()
{


void (*fp)();
fp=&fun1;
fp();

fp=&fun2;
fp();

fp=fun3;//also allowed
fp();

fp=&fun4;
fp();


//if int func(int num1,num2)

int (*fpp)(int,int);
fpp=&funint;
int ans=fpp(10,20);

printf("%d",ans);
return 0;

}