#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

typedef struct {
long mtype;
char mtext[20];
}msgbuf;

int main()
{
	
	msgbuf msg;
	
	key_t mq_key=0x5544aabb;
	int mq_id;
	mq_id=msgget(mq_key,IPC_CREAT|0777);
	printf("message queue id=%d\n",mq_id);

	//checks with this key , any msg queue present or not
	//if not present, it creates a msg queue with given permisions
	
	
	printf("Enter the msg text::");
	fgets(msg.mtext,20,stdin);

	printf("Enter the msg type::");
	scanf("%ld",&msg.mtype);

	//read string first then int to avoid buffer issues
	



	msgsnd(mq_id,&msg,sizeof(msg),0);
	//OR  msgsnd(mq_id,&msg,sizeof(msg),IPC_NOWAIT);

	printf("message sent\n");





}
