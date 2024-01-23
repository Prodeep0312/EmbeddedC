#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>



int main()
{
	
	key_t shmkey=0xabcd1287;
	int shmid;
	shmid=shmget(shmkey,0,0);
	// 2nd para->size of shared memory
	printf("shmid:%d",shmid);

	//process needs to attatch to shared memory

	char* rptr=shmat(shmid,NULL,SHM_RDONLY);
	//2nd para ->address where to attach
	//3rd para-> 0=readwrite
	//SHM_RDONLY=only read

	printf("%s\n",rptr);

	//detach

	shmdt(rptr);

}

