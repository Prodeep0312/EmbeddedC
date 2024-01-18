#include<stdio.h>

typedef struct Test
{

unsigned int var1:5;
//var 1 takes only 5 bits out of 32 bits
unsigned int var2:3;
unsigned int var3:4;
unsigned int var4:3;
unsigned int var5:1;
unsigned int var6:5;
unsigned int var7:4;
unsigned int var8:2;
unsigned int var9:3;

}Test;

void main()
{
Test obj;

printf("Size of obj :%ld",sizeof(obj));

//36 normally bytes
//bit field se size is 4 bytes

//if var8:5 and var9:4
//new size: 8 bytes

}