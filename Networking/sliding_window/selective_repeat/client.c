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

int main() {
    int sock_d;
    char message[MAX];
    struct sockaddr_in server_addr;
    sock_d = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_d == -1) { printf("Socket creation failed\n"); exit(1); }
    printf("Socket created successfully\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    if (connect(sock_d, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed.\n"); close(sock_d); exit(1);
    }
    printf("Connected to the server successfully\n");

    int status, error_frame;
    while (1) {
        recv(sock_d, message, sizeof(message), 0);
        if (strcmp(message, "EXIT") == 0) {
            printf("Transmission completed\n");
            break;
        }
        printf("Received frames: %s\n", message);
        printf("Any Error:\n1-Yes\n0-No\n");
        scanf("%d", &status);

        if (status == 0) {
            printf("Transmission successful\n");
            error_frame = 0;
            send(sock_d, &error_frame, sizeof(error_frame), 0);
        } else {
            printf("Enter the frame which has error:\n");
            scanf("%d", &error_frame);
            send(sock_d, &error_frame, sizeof(error_frame), 0);

            
            char single_frame[2];
            recv(sock_d, single_frame, sizeof(single_frame), 0);
            printf("Retransmitted Frame received: %c\n", single_frame[0]);
        }
    }

    close(sock_d);
    return 0;
}