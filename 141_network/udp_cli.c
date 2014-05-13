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
	char sendline[1000000];
	char recvline[1000000];
	char buf[BUFSIZ];
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

	int p = 0;
	int count = 0;

	while (fgets(buf, BUFSIZ,stdin) != NULL)
	{
		p += 1;
		int n;
		n = atoi(buf);
		sendint[0] = n;
		sendto(sockfd,sendint,10,0,
				(struct sockaddr *)&servaddr,sizeof(servaddr));
		n=recvfrom(sockfd,recvint,10,0,NULL,NULL);
		count += recvint[0];
		printf("----------------\n");
		printf("recv	: %d\n", recvint[0]);
		printf("count	: %d\n", count);
		printf("----------------\n");
		if (p == 2){
			if (recvint[1] == count){
				printf("recv total = %d\n", recvint[1]);
				printf("count = %d\n", count);
				printf("end event");
				break;
			} else {
				p = 0;
				count = 0;
				sendint[0] = 0;
				sendint[1] = 0;
			}
		}
	}
}
