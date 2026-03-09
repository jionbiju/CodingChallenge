#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main(){
    int sock_d;
    struct sockaddr_in server_addr,client_addr;
    sock_d = socket(AF_INET,SOCK_DGRAM,0);
    if(sock_d == -1){
        printf("Socket creation failed\n");
        exit(1);
    }
    else{
        printf("Socket created successfully\n");
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(2000);

    if(bind(sock_d,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0){
        printf("Bind failed\n");
        close(sock_d);
        exit(1);
    }
    printf("Binding successful\n");

    int num_frames,frame,ack;
    int size_of_client = sizeof(client_addr);
    recvfrom(sock_d,&num_frames,sizeof(num_frames),0,(struct sockaddr *)&client_addr,&size_of_client);
    printf("Number of frames to receive is %d\n",frame);
    while(1){
        recvfrom(sock_d,&frame,sizeof(frame),0,(struct sockaddr *)&client_addr,&size_of_client);
        if(frame == -999){
            printf("Termination signal received.Exiting...\n");
            break;
        }
        printf("Received Frame is %d\n",frame);
        printf("Enter the ack for the frame %d:(1 for success, -1 for failure)\n",frame);
        scanf("%d",&ack);
        sendto(sock_d,&ack,sizeof(ack),0,(struct sockaddr *)&client_addr,size_of_client);

    }
    close(sock_d);
    return 0;

}
/*
OUTPUT
Socket created successfully
Binding successful
Number of frames to receive is 0
Received Frame is 0
Enter the ack for the frame 0:(1 for success, -1 for failure)
1
Received Frame is 1
Enter the ack for the frame 1:(1 for success, -1 for failure)
-1
Received Frame is 1
Enter the ack for the frame 1:(1 for success, -1 for failure)
1
Received Frame is 2
Enter the ack for the frame 2:(1 for success, -1 for failure)
-1
Received Frame is 2
Enter the ack for the frame 2:(1 for success, -1 for failure)
1
Received Frame is 3
Enter the ack for the frame 3:(1 for success, -1 for failure)
1
Termination signal received.Exiting..
*/