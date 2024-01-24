#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>

int cnum=0;

void convertToUpperCase(char* str)
{

	for(int i=0;*(str+i)!='\0';i++)
	{
	
	
		if(*(str+i)>=97 && *(str+i)<=121)
		{
		
			*(str+i)-=32;
		}
	
	}

}
int main()
{
	int sd,cd;
	char buff[1024];
	struct sockaddr_in addr,cliaddr;


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
	addr.sin_addr.s_addr=inet_addr("10.0.2.16");
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
		
		while(1)
		{
			printf("Waiting for clients..\n");
			int len=sizeof(cliaddr);
			cd=accept(sd,(struct sockaddr *)&cliaddr,&len);
			printf("Client port no is :: %d\n",cliaddr.sin_port);
			
			printf("Client request accepted\n");
			printf("cd::%d \n",cd);
			cnum++;
			if(fork()==0)
			{
				while(1)
				{
				
					read(cd,buff,1024);
					printf("client %d data::%s\n",cnum,buff);
					convertToUpperCase(buff);
					write(cd,buff,1024);
				}
			
			}
			
			else
			{
				close(cd);
			
			}
			
		}
		
	
	}
	


	}


}
