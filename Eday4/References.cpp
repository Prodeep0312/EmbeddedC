#include <iostream>
using namespace std;


int main()
{
int num1=99 , num2=76;
int &ref=num1; //cannot refer to any other variable now

cout<<ref<<num1<<endl; //99 99

ref=125;//num1 =125

ref++; //num1++

cout<<ref<<num1<<endl; //126 126

ref=num2; //num1=num2

cout<<ref<<num1<<endl; // 76 76


}




