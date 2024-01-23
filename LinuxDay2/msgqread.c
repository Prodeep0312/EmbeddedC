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
	msgbuf readmsg;

	mq_id=msgget(mq_key,0);
	printf("message queue id=%d\n",mq_id);
	if(mq_id == -1)
	perror("");

	msgrcv(mq_id,&readmsg,sizeof(readmsg),0,0);

	// if 4th parameter is 0->fifo order
	//5th parameter -> 0 or IPC_NOWAIT
	
	
	printf("message type read is %ld\n",readmsg.mtype);
	printf("message text read is %s\n",readmsg.mtext);





}
