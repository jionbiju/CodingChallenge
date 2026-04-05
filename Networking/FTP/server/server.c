#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8080
#define MAX 100

int main()
{
    int num, new_socket, status;
    char data[MAX];
    char filename[20];
    FILE *fp;
    socklen_t addr_size;
    num = socket(AF_INET, SOCK_STREAM, 0);
    if (num == -1)
    {
        printf("Socket creation failed\n");
        close(num);
        return 1;
    }
    printf("Socket created successfully\n");
    // Server Binding
    struct sockaddr_in server_addr, client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(num, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Bind failed\n");
        close(num);
        return 1;
    }
    printf("Bind sucessfully\n");
    // Listen
    if (listen(num, 5) == -1)
    {
        printf("Listen failed\n");
        close(num);
        return 1;
    }
    printf("Server listening to the port:%d\n", PORT);
    addr_size = sizeof(client_addr);
    new_socket = accept(num, (struct sockaddr *)&client_addr, &addr_size);
    if (new_socket == -1)
    {
        perror("Accept failed\n");
        close(new_socket);
        return 1;
    }
    printf("Connection accepted\n");
    recv(new_socket, filename, sizeof(filename), 0);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error while opening the file\n");
        close(num);
        fclose(fp);
        close(new_socket);
        return 0;
    }
    fread(data,1, sizeof(data), fp);
    
        if (send(new_socket, data, sizeof(data), 0) == -1)
        {
            printf("Error in sending data\n");
            exit(1);
        }
    
    printf("File Transfer completed\n");
    close(num);
    close(new_socket);
    fclose(fp);
    return 0;
}