#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define RECV_BUF_LEN (1024)
#define PORT (1989)
#define LISTEN_BACKLOG (16)

char recv_buffer[RECV_BUF_LEN + 1];

int main(void)
{
    int tcp_socket;
    int incoming_socket;
    size_t received;
    struct sockaddr_in socket_address;
    struct sockaddr_in incoming_address;
    socklen_t addrlen;

    tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_socket == -1) {
        perror("Failed to create socket");
        return 1;
    }

    memset(&socket_address, 0, sizeof(socket_address));
    socket_address.sin_family = AF_INET;
    socket_address.sin_port = htons(PORT);
    socket_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if (bind(tcp_socket, (struct sockaddr*)&socket_address,
             sizeof(socket_address)) == -1) {
        perror("Failed to bind socket");
        close(tcp_socket);
        return 1;
    }

    if (listen(tcp_socket, LISTEN_BACKLOG) == -1) {
        perror("Failed to listen on socket");
        close(tcp_socket);
        return 1;
    }

    memset(&incoming_address, 0, sizeof(incoming_address));
    addrlen = sizeof(incoming_address);
    incoming_socket = accept(tcp_socket, (struct sockaddr*)&incoming_address, &addrlen);
    if (incoming_socket == -1) {
        perror("Failed to accept connections on socket");
        close(tcp_socket);
        return 1;
    }

    printf("Incoming connections received!\n");

    received = recv(incoming_socket, recv_buffer, RECV_BUF_LEN, 0);
    while (received > 0) {
        if (received == (size_t)-1) {
            perror("Failed to receive data from socket");
            close(tcp_socket);
            close(incoming_socket);
            return 1;
        }        

        recv_buffer[received] = '\0';
        puts(recv_buffer);
        received = recv(incoming_socket, recv_buffer, RECV_BUF_LEN, 0);
    }

    printf("End of file\n");
    close(incoming_socket);
    close(tcp_socket);

    return 0;
}

/* eof */
