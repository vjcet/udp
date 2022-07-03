#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Error start");
		exit(0);
	}
	
	int port=atoi(argv[1]),clientSocket=socket(PF_INET,SOCK_DGRAM,0);
	struct sockaddr_in serverAddr;
	
	socklen_t addr_size;
	char buffer[1024];

	
	
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(port);
	serverAddr.sin_addr.s_addr=INADDR_ANY;
	
	printf("Enter Data to be Sent:");
	scanf("%s",buffer);
	sendto(clientSocket,buffer,1024,0,(struct sockaddr*)&serverAddr,sizeof(serverAddr));

}

