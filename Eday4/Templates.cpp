
#include<iostream>
using namespace std;

template<typename T> 
void Myswap(T &a, T &b)

{
	T temp;
	temp=a;
	a=b;
	b=temp;


}
int main()
{
   int a=3,b=8;
   cout<<"Before Swapping "<<"a:"<<a<<" b:"<<b<<endl;
   Myswap(a,b);
   cout<<"After Swapping "<<"a:"<<a<<" b:"<<b<<endl;
   
   char  p='A',q='B';
   cout<<"Before Swapping "<<"p:"<<p<<" q:"<<q<<endl;
   Myswap(p,q);
   cout<<"After Swapping "<<"p:"<<p<<" q:"<<q<<endl;
}