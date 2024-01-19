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



Emp employees[5];

printf("Size of employees:%ld \n",sizeof(employees));

for(int i=0;i<5;i++)

{
printf("Enter Employee %d id :",i+1);
scanf("%d",&employees[i].eid);

printf("Enter Employee %d salary :",i+1);
scanf("%f",&employees[i].sal);

printf("Enter Employee %d name :",i+1);
scanf("%s",employees[i].name);

}

for(int i=0;i<5;i++)
{
printf("EID :%d\n",employees[i].eid);
printf("Salary :%f \n",employees[i].sal);
printf("Name :%s\n",employees[i].name);


}


return 0;

}