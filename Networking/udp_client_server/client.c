#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main() {
    int sock_d,num;
    struct sockaddr_in server_addr;
    sock_d = socket(AF_INET,SOCK_DGRAM,0);
    if(sock_d == -1){
        printf("Failed to creation socket");
        exit(1);
    }
    else{
        printf("Socket created successfully\n");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8000);

   
    printf("Enter a number:");
    scanf("%d",&num);
    int size_of_server = sizeof(server_addr);
    sendto(sock_d,&num,sizeof(num),0,(struct sockaddr *)&server_addr,size_of_server);
    close(sock_d);
    return 0;
}