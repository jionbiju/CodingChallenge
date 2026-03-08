#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080

int main(){
    int sock_d,new_sock_d;
    char message[1024],msg2[1024];
    struct sockaddr_in server_addr,clinet_addr;
    sock_d = socket(AF_INET,SOCK_STREAM,0);
    if (sock_d == -1){
        printf("Socket creation failed\n");
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(sock_d,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0){
        printf("Bind failed");
        exit(1);
    }
    if(listen(sock_d,5) < 0){
        exit(1);
    }
    else{
        printf("Server listening to the port %d\n",SERVER_PORT);
    }
    int size_of_client_addr = sizeof(clinet_addr);
    new_sock_d = accept(sock_d,(struct sockaddr *)&clinet_addr,&size_of_client_addr);

    
    while(1){
        recv(new_sock_d,message,sizeof(message),0);
        printf("Client:%s\n",message);
        printf("Server:");
        fgets(msg2,sizeof(msg2),stdin);
        msg2[strcspn(msg2,"\n")] = 0;
        if (strcmp(msg2,"end") == 0 ){
            break;
        }
        send(new_sock_d,msg2,sizeof(msg2),0);
    }
    close(sock_d);
    close(new_sock_d);
}
/*
OUTPUT
Server listening to the port 8080
Client:Hi server this is clinet
Server:oh hi i am server
Client:how are you
Server:i am fine
Client:how are you
Server:end
*/