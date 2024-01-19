#include <stdio.h>
#include<stdlib.h>



typedef struct emp
{

int eid;
float sal;
char name[20];
char email[20];
} emp;

void main()
{


emp *ptr;

emp e1={1234,99000.88,"Rahul","Rahul@gmail.com"}; 
emp e2={1235,99000.67,"Hardik","Hardik@gmail.com"}; 

ptr=&e1;

printf("e1 eid=%d\n",ptr->eid);
printf("e1 sal=%f\n",ptr->sal);
printf("e1 name=%s\n",ptr->name);
printf("e1 email=%s\n",ptr->email);

ptr=&e2;

printf("e2 eid=%d\n",ptr->eid);
printf("e2 sal=%f\n",ptr->sal);
printf("e2 name=%s\n",ptr->name);
printf("e2 email=%s\n",ptr->email);

// -> is used as there are multiple data in emp ..so * not used


return 0;

}