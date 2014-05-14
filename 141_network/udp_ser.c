/* Sample UDP server */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
	int sockfd,n;
	struct sockaddr_in servaddr,cliaddr;
	socklen_t len;
	char buf[100];
	int recvint[10];
	int sendint[10];

	sockfd=socket(AF_INET,SOCK_DGRAM,0);

	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(32000);
	bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

	int storage = 0;
	
	for (;;)
	{		
		len = sizeof(cliaddr);
		n = recvfrom(sockfd,recvint,10,0,(struct sockaddr *)&cliaddr,&len);
		storage = storage + recvint[0];
		if (recvint[1] == -1){
			storage = 0;
		}
		sendint[0] = storage;
		printf("storage : %d\n", storage);
		printf("receive number : %d\n", recvint[1]);
		sendto(sockfd,sendint,10,0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
	}
}
