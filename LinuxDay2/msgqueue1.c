#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

typedef struct {
long mtype;
char mtext[20];
}msgbuf;

int main()
{
	key_t mq_key=0x5544aabb;
	int mq_id;
	msgbuf msg;

	mq_id=msgget(mq_key,0);
	printf("message queue id=%d\n",mq_id);
	
//checks with this key , any msg queue present
//displays -1 as no msg queue is there in the system


	




}
