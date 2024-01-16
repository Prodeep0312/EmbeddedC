#include <stdio.h>

int main() {
   
   int num1,num2;
   printf("Enter 1st  number:");
   scanf("%d",&num1);
   
      printf("Enter 2nd number:");
   scanf("%d",&num2);
   
   printf("%d\t %d\n ",num1,num2);
 
 num1=num1 ^ num2;
 num2=num1 ^ num2;
 num1=num1 ^ num2;
 
 /*
 n1=n1+n2
 n2=n1-n2
 n1=n1-n2
 */
 printf("%d\t %d\n ",num1,num2);
 
    return 0;
}