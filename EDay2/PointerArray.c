
#include<stdio.h>
#include<stdlib.h>

int main()
{
int size,max;
printf("Enter size of array:");
scanf("%d",&size);

int *ptr=malloc(sizeof(int)* size);

if(ptr==NULL)
{
printf("Allocation Failure\n");

}

else
{
	printf("Enter %d elements",size);

	for(int i=0;i<size;i++)
	{
		scanf("%d",ptr+i);
	}

	 max=*ptr;

	for(int i=1;i<size;i++)
	{	
		if(*(ptr+i)>max)
			{
				max=*(ptr+i);
			}
	}

	printf("Max:%d",max);
	if(ptr!=NULL) // to make sure free is not applied twice
	{
		free(ptr);
		ptr=NULL;
		}
	

}	


return 0;
}