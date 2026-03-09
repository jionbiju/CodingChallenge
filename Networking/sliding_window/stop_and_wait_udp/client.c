#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main(){
    int sock_d;
    struct sockaddr_in server_addr;
    sock_d = socket(AF_INET,SOCK_DGRAM,0);
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
    server_addr.sin_port = htons(2000);

    int frames,ack;
    printf("Enter number of frames to send\n");
    scanf("%d",&frames);
    sendto(sock_d,&frames,sizeof(frames),0,(struct sockaddr *)&server_addr,sizeof(server_addr));

    for(int i=0; i<frames; i++){
        ack=-1;
        while(ack != 1){
            printf("\nSending Frame %d\n",i);
            sendto(sock_d,&i,sizeof(i),0,(struct sockaddr *)&server_addr,sizeof(server_addr));
            printf("Waiting for acknowledgement...\n");
            recvfrom(sock_d,&ack,sizeof(ack),0,NULL,NULL);
            if(ack == -1){
                printf("Negative ack received.Retransmitting the frame %d\n",i);
            }
        }
        printf("Frame %d acknowledgement is successful\n",i);
    }
    int end_signal = -999;
    sendto(sock_d,&end_signal,sizeof(end_signal),0,(struct sockaddr *)&server_addr,sizeof(server_addr));
    printf("All Frames are send successfully\n");


    close(sock_d);
    return 0;

}
/*
OUTPUT
Socket created successfully
Enter number of frames to send
4

Sending Frame 0
Waiting for acknowledgement...
Frame 0 acknowledgement is successful

Sending Frame 1
Waiting for acknowledgement...
Negative ack received.Retransmitting the frame 1

Sending Frame 1
Waiting for acknowledgement...
Frame 1 acknowledgement is successful

Sending Frame 2
Waiting for acknowledgement...
Negative ack received.Retransmitting the frame 2

Sending Frame 2
Waiting for acknowledgement...
Frame 2 acknowledgement is successful

Sending Frame 3
Waiting for acknowledgement...
Frame 3 acknowledgement is successful
All Frames are send successfully
*/