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

	char data[50]="HELLO VIRAT KOHLI ";

	shm_id=shmget(key_shm,0,0);
	printf("shm id =%d\n",shm_id);

	sem_id=semget(key_sem,0,0);
	//2nd parametr->no of sempahore inside array
	printf("sem id =%d\n",sem_id);
	

	printf("Process 1 trying to take semaphore\n");

	//s index
	s.sem_num=0;

	//if s is already set to 0, s-- wont happen
	s.sem_op=-1;

	//0->wait or   IPC_NOWAIT
	s.sem_flg=0;


	//s--
	semop(sem_id,&s,1);
	printf("Process1 takes semaphore \n");

	char* ptr=shmat(shm_id,NULL,0);
	printf("Process1 attaches to shared memory \n");
	printf("Process1 is writing in  shared memory \n");

	int i;
	for(i=0;data[i]!='\0';i++)
	{
		printf("Process 1 writing :%c\n",data[i]);
		*(ptr+i)=data[i];
		sleep(1);
	}

	*(ptr+i)='\0';
	printf("Process1 completes writing\n");

	//detach

	shmdt(ptr);

	printf("Process1 trying to release the semaphore\n");


	s.sem_num=0;
	s.sem_op=+1;
	s.sem_flg=0;
	semop(sem_id,&s,1);

	printf("Process1 releases the semaphore\n");





	
	


}
