#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>


using namespace std;

class A{
public:

void Show();

};

class B{
public:

void Show();

};



void A::Show()

    {
        cout<<"In class A"<<endl;
    }
    
void B::Show()

    {
        cout<<"In class B"<<endl;
    }


int main()
{
   A a;
   a.Show();
   
   B b;
   b.Show();
}