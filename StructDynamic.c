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
ptr=malloc(sizeof(emp));



printf("Enter e1 eid:\n");
scanf("%d",&ptr->eid);

printf("Enter e1 salary:\n");
scanf("%f",&ptr->sal);

printf("Enter e1 name:\n");
scanf("%s",ptr->name);

printf("Enter e1 email:\n");
scanf("%s",ptr->email);

printf("e1 eid=%d\n",ptr->eid);
printf("e1 sal=%f\n",ptr->sal);
printf("e1 name=%s\n",ptr->name);
printf("e1 email=%s\n",ptr->email);

free(ptr);


return 0;

}