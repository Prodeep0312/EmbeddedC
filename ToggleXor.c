//  Toggle multiple Bits

#include <stdio.h>
#define BIT_3 1<<3
#define BIT_4 1<<4
#define BIT_5 1<<5
#define BIT_6 1<<6


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
   
   num=num ^ (BIT_3|BIT_4|BIT_5|BIT_6);
   displayBinary(num);
    return 0;
}