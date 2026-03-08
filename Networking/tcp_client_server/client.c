
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock_d;
    char buffer[BUFFER_SIZE],ser_msg[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    sock_d = socket(AF_INET,SOCK_STREAM,0);
    if (sock_d == -1) {
        printf("Could not create socket\n");
        return 1;
    }
    else {
        printf("Socket created successfully\n");
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_addr.sin_port= htons(SERVER_PORT);

    if(connect(sock_d,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0){
        printf("Connection failed\n");
        return 1;
    }
    while(1){
        printf("Client:");
        fgets(buffer,BUFFER_SIZE,stdin);
        buffer[strcspn(buffer,"\n")] = 0;
        if (strcmp(buffer,"end") == 0 ){
            break;
        }
        send(sock_d,buffer,BUFFER_SIZE,0);
        recv(sock_d,ser_msg,BUFFER_SIZE,0);
        printf("Server:%s\n",ser_msg);
    }
    
    close(sock_d);

}
/*
OUTPUT
Socket created successfully
Client:Hi server this is clinet
Server:oh hi i am server
Client:how are you
Server:i am fine
Client:end
*/