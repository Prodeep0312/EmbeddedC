#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<fcntl.h>


int main()
{
	key_t key_shm=0xaa11bb22,key_sem=0xccdd3344;
	int shm_id,sem_id;
	shm_id=shmget(key_shm,1650,IPC_CREAT|0777);
	printf("shm id =%d\n",shm_id);

	sem_id=semget(key_sem,1,IPC_CREAT|0777);
	//2nd parametr->no of sempahore inside array
	printf("sem id =%d\n",sem_id);
	

	//initialize sem with 1
	//2 parameter is sem index
	semctl(sem_id,0,SETVAL,1);


}
