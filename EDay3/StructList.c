#include <stdio.h>

typedef struct emp
{

int eid;
float sal;
char name[20];
char email[20];
} EMP;

void main()
{



//EMP is UDDT

EMP e1={1234,99000.88,"Rahul","Rahul@gmail.com"}; 
EMP e2={.eid=9876,.email="Hardik@gmail.com"};

printf("Employee1 id: %d \n", e1.eid);
printf("Employee1 sal: %f \n", e1.sal);
printf("Employee1 name: %s \n", e1.name);
printf("Employee1 email: %s \n", e1.email);


printf("Employee2 id: %d \n", e2.eid);
printf("Employee2 sal: %f \n", e2.sal);
printf("Employee2 name: %s \n", e2.name);
printf("Employee2 email: %s \n", e2.email);






}