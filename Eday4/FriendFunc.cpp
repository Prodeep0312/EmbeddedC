#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

class myClass
{
private:
int a,b;
public:

myClass(int x , int y)
{
    a=x;
    b=y;
    
}

void Show()
{
   cout<<"a:"<<a<<"b:"<<b<<endl; 
    
}
friend void myfun();
friend int main();
};


void myfun()
{
cout<<"In myfunc()"<<endl;

myClass o1(99,88);
o1.Show();

o1.a=10;
o1.b=20;
o1.Show();

}

int main()
{
    myClass obj1(20,30);
    obj1.Show();
    
    obj1.a=33;
    obj1.b=69;
    obj1.Show();
    
    myfun();
    
    
    return 0;
}