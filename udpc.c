#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	int clientSocket=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in serverAddr;
	char buffer[1024];
	
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=4040;
	serverAddr.sin_addr.s_addr=INADDR_ANY;
	
	printf("Enter Data to be Sent:");
	scanf("%s",buffer);
	sendto(clientSocket,buffer,1024,0,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
}

