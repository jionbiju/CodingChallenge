#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define BUFFER_SIZE 100
int main()
{
    int num;
    char filename[20];
    char data[100];
    FILE *fp;
    num = socket(AF_INET, SOCK_STREAM, 0);
    if (num == -1)
    {
        printf("Socket creation failed\n");
        return 1;
    }
    printf("Socket created successfully\n");
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(num, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Connection failed\n");
        close(num);
        return 1;
    }
    printf("Connected to the server\n");
    printf("Enter the file name:\n");
    scanf("%s", filename);
    send(num, filename, sizeof(filename), 0);
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error while opening the file\n");
        close(num);
        fclose(fp);
        return 0;
    }
   recv(num, data, sizeof(data), 0);
    
        fputs(data, fp);

    printf("File downloaded\n");
    fclose(fp);
    close(num);
    return 0;
}