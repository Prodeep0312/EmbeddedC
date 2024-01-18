
#include <stdio.h>
#include<stdlib.h>

typedef struct address{
int Hno;
int PIN;
char apt_name[20];
char area_name[20];
char city[20];

}address;


typedef struct emp{
int eid;
float sal;
char name[20];
address addr;

}emp;

void main()
{

emp e1={123,98000,"Prodeep",{115,560043,"Prestige ","Horamavau","Bangalore"}};

emp *p1;
p1=&e1;


printf("Employee id:%d",p1->eid);
printf("Employee Hno:%d",p1->addr.Hno);

return 0;

}