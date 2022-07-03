#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	
	int serverSocket,port=atoi(argv[1]);
	struct sockaddr_in serverAddr,newAddr;
	
	socklen_t addr_size;
	char buffer[1024];

	serverSocket=socket(AF_INET,SOCK_DGRAM,0);

	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(port);
	serverAddr.sin_addr.s_addr=INADDR_ANY;
	
	bind(serverSocket,(struct sockaddr*)&serverAddr, sizeof(serverAddr));
		
	addr_size=sizeof(newAddr);
	recvfrom(serverSocket,buffer,1024,0,(struct sockaddr*)&newAddr,&addr_size);
	printf("DATA RECEVIED:%s",buffer);
}
 
