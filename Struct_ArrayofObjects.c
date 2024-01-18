#include <stdio.h>
#include<stdlib.h>



typedef struct emp
{

int eid;
float sal;
char name[20];

} Emp;

void main()
{

//array of Emp type with 5 objects 
//total size:28x5 =140 bytes



Emp employees[5]={ {1,10000,"abc"},{2,20000,"pqr"},{3,30000,"xyz"},{4,40000,"mno"},{5,50000,"stu"}};

printf("Size of employees:%ld \n",sizeof(employees));

for(int i=0;i<5;i++)
{
printf("EID :%d\n",employees[i].eid);
printf("Salary :%f \n",employees[i].sal);
printf("Name :%s\n",employees[i].name);


}


return 0;

}