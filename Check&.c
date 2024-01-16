//Check whether 6th bit is set or not
#include <stdio.h>
#define BIT_6 1<<6

int main() {
   int num;
   printf("Enter a number");
   scanf("%d",&num);
   
   if((num & BIT_6)==0)
   {
       printf("Bit is set to 0 /OFF\n");
   }
   else
   {
        printf("Bit is set to 1 /ON\n");
   }
   
   

    return 0;
}