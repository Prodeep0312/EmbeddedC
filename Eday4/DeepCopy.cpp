#include <iostream>
#include <cstring>
using namespace std;

class myClass {
private:
    int eid;
    float sal;
    char* name;

public:
    
    myClass(int id, float salary, const char* empName) {
        eid = id;
        sal = salary;
        name = new char[strlen(empName) + 1];
        strcpy(name, empName);
    }

    // User-defined Copy Constructor for Deep Copy
    myClass(myClass  &o) { //o->o1 this->o2
        this->eid = o.eid;
        this->sal = o.sal;
        this->name = new char[strlen(o.name) + 1];//new address
        strcpy(name, o.name);//then copy contents to that new address
    }

    
    void changeEid(int newEid) {
        eid = newEid;
    }

    
    void changeSal(float newSal) {
        sal = newSal;
    }

    
    void changeName(const char* newName) {
        
        strcpy(name, newName);
    }

    
    void show() {
        cout << "Employee ID: " << eid << "\nSalary: " << sal << "\nName: " << name << endl;
        printf("Address of name string: %p \n", name);
    }

    
    ~myClass() {
        delete[] name;
    }
};

int main() {
    
    myClass ob1(101, 50000.0, "Rahul Dravid");

    
    myClass ob2(ob1);

    
    cout << "Details of ob1:\n";
    ob1.show();

   
    cout << "\nDetails of ob2 (deep copied from ob1):\n";
    ob2.show();

    
    ob1.changeEid(102);
    ob1.changeSal(55000.0);
    ob1.changeName("Virat Kohli");

    
    cout << "\nDetails of ob1 after modification:\n";
    ob1.show();

    cout << "\nDetails of ob2 after modification:\n";
    ob2.show();

    return 0;
}