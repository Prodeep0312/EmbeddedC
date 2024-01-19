//  Decimal to binary
#include <stdio.h>

int main() {
   
   int num;
   printf("Enter a number");
   scanf("%d",&num);
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
  
   
   

    return 0;
}
