//
//  main.c
//  webserver-ex
//
//  Created by 김 주희 on 2014. 3. 28..
//  Copyright (c) 2014년 kimjoohwee. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char* makePath(char* char1){
    
    char result[32] = "";
    char mysite[10] = "mysite";
    
    strcpy(result, mysite);
    if (strcmp(char1, "/") == 0) {
        strcat(result, "/index.html");
        
    } else {
        strcat(result, char1);
    }
    char1 = malloc(64);
    strcat(char1, result);
    return char1;
}


/* Sample TCP server */

int main(int argc, char**argv)
{
    int listenfd,connfd,n;
    struct sockaddr_in servaddr,cliaddr;
    socklen_t clilen;
    char mesg[4096];
    char header[] = "HTTP/1.0 200 OK\r\nDate: Wed, 12 Mar 2014 00:14:10 GMT\r\n\r\n";
    char buf[BUFSIZ];
    
    listenfd=socket(AF_INET,SOCK_STREAM,0);
    
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(32000);
    bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    
    listen(listenfd,1024);
    
    for(int i = 0; i < 100;i++) {
        clilen=sizeof(cliaddr);
        connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&clilen);
        printf("connected (%d)\n", connfd);
        
        if (connfd > 0) {
            n = recv(connfd,mesg,4096,0);
            mesg[n] = 0;
            printf("=====\n%s=====\n", mesg);
            send(connfd,header,strlen(header),0);
            
            char* oSearch;
            char* result;
            oSearch = strtok(mesg, " ");
            oSearch = strtok(NULL, " ");
            
            result = makePath(oSearch);
            
            int fd = open(result, O_RDONLY);
            while ((n = read(fd, buf, BUFSIZ)) > 0) {
                send(connfd,buf,n,0);
            }
            close(fd);
            close(connfd);
        }
    }
}