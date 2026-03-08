#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main() {
    int sock_d,num;
    struct sockaddr_in server_addr,client_addr;
    sock_d = socket(AF_INET,SOCK_DGRAM,0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8000);

    if(bind(sock_d,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0){
        printf("Bind failed");
        exit(1);
    }
    else{
        printf("Binded succesfully\n");
    }
    int size_of_client = sizeof(client_addr);
    recvfrom(sock_d,&num,sizeof(num),0,(struct sockaddr *)&client_addr,&size_of_client);
    int og=num,remainder,rev=0;
    while(num!=0){
        remainder=num%10;
        rev=rev*10+remainder;
        num=num/10;
    }
    if(rev == og){
        printf("palindrome\n");
    }
    else{
        printf("Not Palindrome\n");
    }
    
    close(sock_d);
    
    return 0;
}