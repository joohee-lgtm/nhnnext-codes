/* Sample UDP client */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char**argv)
{
	int sockfd,n;
	struct sockaddr_in servaddr,cliaddr;
	char buf[10000];
	int sendint[10];
	int recvint[10];

	if (argc != 2)
	{
		printf("usage: ex04c <IP address>\n");
		exit(1);
	}

	sockfd=socket(AF_INET,SOCK_DGRAM,0);

	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(argv[1]);
	servaddr.sin_port=htons(32000);

	int count = 0;
	int storage = 0;

	while (fgets(buf, BUFSIZ,stdin) != NULL)
	{
		int usr_buf;
		count += 1;
		usr_buf = atoi(buf);
		sendint[0] = usr_buf;
		sendint[1] = 0;
		storage += usr_buf;
		sendto(sockfd,sendint,10,0,
				(struct sockaddr *)&servaddr,sizeof(servaddr));
		n=recvfrom(sockfd,recvint,10,0,NULL,NULL);
		
		printf("------------------------------------------------------\n");
		printf("number to server	: %d\n", sendint[0]);
		printf("number from server	: %d\n", recvint[0]);
		printf("------------------------------------------------------\n");
		if (count == 2){
			printf("first + second		: %d\n", storage);
			printf("number from server	: %d\n", recvint[0]);
			sendint[1] = -1;
			sendto(sockfd,sendint,10,0,
					(struct sockaddr *)&servaddr, sizeof(servaddr));
			if (storage == recvint[0]){
				printf("end event\n");
				break;
			} else {
				printf("restart\n");
			}
		}
	}
}
