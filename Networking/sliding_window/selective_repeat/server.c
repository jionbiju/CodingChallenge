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
    int sock_d, new_sock_d;
    char buffer[MAX], frame[MAX];
    struct sockaddr_in server_addr, client_addr;
    sock_d = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_d == -1) { printf("Socket creation failed\n"); exit(1); }
    printf("Socket created successfully\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    if (bind(sock_d, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Bind failed\n"); close(sock_d); exit(1);
    }
    printf("Binded successfully\n");
    if (listen(sock_d, 5) < 0) {
        printf("Listen failed\n"); close(sock_d); exit(1);
    }
    printf("Server listening to the port %d\n", PORT);

    int size_of_client = sizeof(client_addr);
    new_sock_d = accept(sock_d, (struct sockaddr *)&client_addr, &size_of_client);
    if (new_sock_d == -1) {
        printf("Accept failed\n"); close(sock_d); exit(1);
    }
    printf("Connection accepted\n");

    printf("Enter a message:\n");
    scanf("%s", buffer);
    int len = strlen(buffer);
    int i = 0, status;

    while (i < len) {
        memset(frame, 0, sizeof(frame));
        strncpy(frame, buffer + i, WINDOW_SIZE);
        frame[WINDOW_SIZE] = '\0';
        for (int j = 0; j < strlen(frame); j++) {
            printf("Sending frame %d:%c\n", i + j, frame[j]);
        }
        send(new_sock_d, frame, sizeof(frame), 0);
        recv(new_sock_d, &status, sizeof(status), 0);

        if (status == 0) {
            printf("No error in frames.\n");
            i += WINDOW_SIZE; // slide window forward
        } else {
            printf("Error in frame %d\n", status);
            // ✅ SELECTIVE REPEAT: retransmit ONLY the single error frame
            char single_frame[2];
            single_frame[0] = buffer[status];
            single_frame[1] = '\0';
            printf("Retransmitting only Frame %d:%c\n", status, buffer[status]);
            send(new_sock_d, single_frame, sizeof(single_frame), 0);
            i += WINDOW_SIZE; // still slide window, other frames were buffered
        }
    }

    send(new_sock_d, "EXIT", 4, 0);
    close(sock_d);
    close(new_sock_d);
    return 0;
}