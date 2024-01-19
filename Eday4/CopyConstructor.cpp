// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class myClass{
    int id;
    float sal;
    
public:

    myClass()
    {
        
    }
    myClass(int m , float n)
    {
        this->id=m;
        this->sal=n;
    }
    
    void show()
    {
        cout<<"EID="<<id<<endl;
        cout<<"SAL="<<sal<<endl;
    }
    ~myClass(){
        cout<<"destructor"<<endl;
    }
};
int main()
{
    myClass ob1(1234,9898.77);
    ob1.show();
   
    
    cout<<"After assignment"<<endl;
     myClass ob2(ob1);
    
    ob2.show();
    
   


}