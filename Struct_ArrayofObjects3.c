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



int size;
printf("Enter no of employees:\n");
scanf("%d",&size);

Emp *p ;
p=malloc(size*sizeof(Emp));

for(int i=0;i<size;i++)

{
printf("Enter Employee %d id :",i+1);
scanf("%d",&(p+i)->eid);
printf("Enter Employee %d salary :",i+1);
scanf("%f",&(p+i)->sal);
printf("Enter Employee %d name :",i+1);
scanf("%s",(p+i)->name);

}



for(int i=0;i<size;i++)
{
printf("EID :%d\n",(p+i)->eid);
printf("Salary :%f \n",(p+i)->sal);
printf("Name :%s\n",(p+i)->name);


}


//Note:Dynamic objects cannot be initialized in C

}