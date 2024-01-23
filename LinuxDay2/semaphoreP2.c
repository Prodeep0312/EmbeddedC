#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<unistd.h>


int main()
{
	key_t key_shm=0xaa11bb22,key_sem=0xccdd3344;
	int shm_id,sem_id;

	//prebuild struct
	struct sembuf s;

	

	shm_id=shmget(key_shm,0,0);
	printf("shm id =%d\n",shm_id);

	sem_id=semget(key_sem,0,0);
	//2nd parametr->no of sempahore inside array
	printf("sem id =%d\n",sem_id);
	

	printf("Process 2 trying to take semaphore\n");

	
	s.sem_num=0;

	
	s.sem_op=-1;

	
	s.sem_flg=0;


	//s--
	semop(sem_id,&s,1);
	printf("Process2 takes semaphore \n");

	char* ptr=shmat(shm_id,NULL,0);
	printf("Process2 attaches to shared memory \n");
	printf("Process2 is reading from  shared memory \n");
	
	int i=0;
	while(*(ptr+i))
	{
		printf("%c\n",*(ptr+i));
		i++;
		sleep(1);
		
	
	
	}
	

	*(ptr+i)='\0';
	printf("Process2 completes reading\n");

	//detach

	shmdt(ptr);

	printf("Process2 trying to release the semaphore\n");


	s.sem_num=0;
	s.sem_op=+1;
	s.sem_flg=0;
	semop(sem_id,&s,1);

	printf("Process2 releases the semaphore\n");




	
	


}
