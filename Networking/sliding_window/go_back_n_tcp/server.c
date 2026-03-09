#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 3000
#define MAX 1024
#define WINDOW_SIZE 4

int main (){
    int sock_d,new_sock_d;
    char buffer[MAX],frame[MAX];
    struct sockaddr_in server_addr,client_addr;
    sock_d = socket(AF_INET,SOCK_STREAM,0);
    if(sock_d == -1){
        printf("Socket creation failed\n");
        close(sock_d);
        exit(1);
    }
    else{
        printf("Socket created successfully\n");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    if(bind(sock_d,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0){
        printf("Bind failed\n");
        close(sock_d);
        exit(1);
    }
    printf("Binded successfully\n");
    if(listen(sock_d,5)<0){
        printf("Listen failed\n");
        close(sock_d);
        exit(1);
    }
    else{
        printf("Server listening to the port %d\n",PORT);
    }
    int size_of_client = sizeof(client_addr);
    new_sock_d = accept(sock_d,(struct sockaddr *)&client_addr,&size_of_client);
    if(new_sock_d == -1){
        printf("Accept failed\n");
        close(new_sock_d);
        close(sock_d);
        exit(1);
    }
    printf("Connection accepted\n");

    printf("Enter a message:\n");
    scanf("%s",buffer);
    int len = strlen(buffer);
    int i=0,j=0,status;
    while(i<len){
        memset(frame,0,sizeof(frame));
        strncpy(frame,buffer+i,WINDOW_SIZE);
        frame[WINDOW_SIZE] = '\0';
        for(int j=0; j<strlen(frame); j++){
            printf("Sending frame %d:%c\n",i+j,frame[j]);
        }
        send(new_sock_d,frame,sizeof(frame),0);
        recv(new_sock_d,&status,sizeof(status),0);
        if(status == 0){
            i+=WINDOW_SIZE;
            printf("No error in frames.\n");
        }
        else{
            printf("Error in frame %d\n",status);
            j=0;
            while(j<WINDOW_SIZE){
                frame[j] = buffer[status+j];
                printf("Retransmitting Frame %d:%c\n",status+j,frame[j]);
                j++;
            }
            frame[j] = '\0';
            send(new_sock_d,frame,sizeof(frame),0);
            i=status+j;
        }
    }
    send(new_sock_d,"EXIT",4,0);
    close(sock_d);
    close(new_sock_d);
    return 0;

}
/*
OUTPUT
Socket created successfully
Binded successfully
Server listening to the port 3000
Connection accepted
Enter a message:
aaaabbbbcccc
Sending frame 0:a
Sending frame 1:a
Sending frame 2:a
Sending frame 3:a
No error in frames.
Sending frame 4:b
Sending frame 5:b
Sending frame 6:b
Sending frame 7:b
Error in frame 6
Retransmitting Frame 6:b
Retransmitting Frame 7:b
Retransmitting Frame 8:c
Retransmitting Frame 9:c
Sending frame 10:c
Sending frame 11:c
No error in frames.
*/