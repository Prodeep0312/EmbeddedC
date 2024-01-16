//  Set a particular bit as 0

#include <stdio.h>
#define BIT_2 1<<2


void displayBinary(int num)
{
     for(auto int i=31;i>=0;i--)
   {
       int maskbit=1<<i;
       if((num & maskbit)==0)
       {
           printf("0");
       }
       else
       {
           printf("1");
       }
   }
   printf("\n");
}
int main() {
   
   int num;
   printf("Enter a number:");
   scanf("%d",&num);
   displayBinary(num);
   
   num=num & ~(BIT_2);
   displayBinary(num);
    return 0;
}