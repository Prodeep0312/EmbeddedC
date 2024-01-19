#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>


using namespace std;

class emp{

int eid;
float salary;
char* name;
const int count;
int &r;

public:


emp(int id , float s, char* n, int num ) :count(num),r(eid)       //initializer list

{

this->eid=id;
this->salary=s;
this->name = new char[strlen(n) + 1];
        strcpy(name, n);

}

void Show()

    {
        
        cout<<"EId="<<eid<<endl;
         cout<<"ESalary="<<salary<<endl;
          cout<<"EName="<<name<<endl;
           cout<<"Ecount="<<count<<endl;
            cout<<"Reference r="<<r<<endl;
        
    }
};

int main()
{
    emp e(123,38000.77,"Prodeep",69);
    e.Show();
    return 0;
}