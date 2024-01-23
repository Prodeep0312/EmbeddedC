#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>



int main()
{
	char data[50]="HELLO CZ SHARED MEM";
	key_t shmkey=0xabcd1287;
	int shmid;
	shmid=shmget(shmkey,950,IPC_CREAT|0777);
	// 2nd parameter->size of shared memory
	printf("shmid:%d",shmid);

	//process needs to attatch to shared memory

	char* ptr=shmat(shmid,NULL,0);
	//2nd para ->address where to attach
	//3rd para-> 0=readwrite
	//SHM_RDONLY=only read

	
	int i;
	//strcpy logic
	for(i=0;data[i]!='\0';i++)
	{

		*(ptr+i)=data[i];
	}

	*(ptr+i)='\0';

	//detach

	shmdt(ptr);

}





