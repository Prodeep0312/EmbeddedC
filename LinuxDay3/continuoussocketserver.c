#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>

int main()
{
	int sd,cd;
	char buff[1024];
	struct sockaddr_in addr;


	//1st->domain (ethernet[diff/same] or unix[same])
	//2nd->conn oriented or conn less
	//3rd->protocol

	if((sd=socket(AF_INET,SOCK_STREAM,0))==-1)
	
	{
		perror("socket");
		exit(0);
	}

	else
	{
	printf("sd=%d\n",sd);
	addr.sin_family=AF_INET;

	//changes string ip to MAC address
	addr.sin_addr.s_addr=inet_addr("10.0.2.15");
	addr.sin_port=8900;

	if(bind(sd,(struct sockaddr *)&addr,sizeof(addr))==-1)
	{
		perror("bind");
		exit(0);
	}
	else
	{
		listen(sd,10);
		printf("Server has started..\n");
		printf("Waiting for clients..\n");
		cd=accept(sd,NULL,NULL);
		printf("Client request accepted\n");

		while(1)
		{
		read(cd,buff,1024);
		printf("%s",buff);
		fgets(buff,1024,stdin);
		write(cd,buff,1024);
		

		}
		
		close(cd);
		close(sd);	
	}
	


	}


}
