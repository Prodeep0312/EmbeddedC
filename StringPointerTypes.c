
#include <stdio.h>
#include<stdlib.h>

void myStringConcat(char *const dest,const char* src)
{
    int indx=0;
    while(dest[indx]!='\0')
    {
        indx++;
    }
    
    int dlen=indx;
    
    int i=0;
    
    while(src[i]!='\0')
    {
        dest[dlen+i]=src[i];
        i++;
    }
    dest[dlen+i]='\0';
    
    
}
void myStringCopy(char *const dest,const char* src)
{   int indx=0;
    while(src[indx]!='\0')
    {
        dest[indx]=src[indx];
        indx++;
    }
    dest[indx]='\0';
}

//constant pointer 
void myStringReverse(char *const s1)
{
    int indx=0;
    while(s1[indx]!='\0')
    {
        indx++;
    }
    
    int len=indx;
    
    int i=0,j=len-1;
    
    while(i<j)
    {
        char temp=s1[i];
        s1[i]=s1[j];
        s1[j]=temp;
        i++;j--;
    }
    s1[len] = '\0'; 
    
    

}

 //pointer constant   
int myStringLength(const char* s1)
{
    
    int indx=0;
    while(s1[indx]!='\0')
    {
        indx++;
    }
    
    
    return indx;
}
//pointer constant
int myStringCompare(const char* s1,const char* s2)
{
    int i=0,j=0;
    while(s1[i]!='\0' && s2[j]!='\0')
    {
        if(s1[i]!=s2[j])
        {
            return 0;
            break;
        }
        else
        {
            i++;
            j++;
        }
        
        
    }
    return 1;
}
int main() {
    // Write C code here
   char *s1;
   s1=malloc(256);
   
   char *s2;
   s2=malloc(256);
   
    char *d2;
   d2=malloc(256);
   
   printf("Enter string 1:\n");
   gets(s1);
   
   printf("Enter string 2:\n");
   gets(s2);
   
   
   int len1=myStringLength(s1);
   printf("Length of string 1:%d \n",len1);
   
   int len2=myStringLength(s2);
   printf("Length of string 2:%d \n",len2);
   
   int cmpr=myStringCompare(s1,s2);
   if(cmpr==0) printf("UnEqual strings\n");
   else   printf("Equal strings\n");
   
   
  
   myStringCopy(d2,s2);
   printf("Original String:%s \n",s2);
   printf("Copied String:%s \n",d2);
   
   myStringConcat(d2,s1);
   printf("Concatenated String:%s \n",d2);
   
   
  
   
   myStringReverse(s1);
   printf("Reversed String 1:%s \n",s1);
   
   myStringReverse(s2);
   printf("Reversed String 2:%s",s2);
   
   return 0;
}