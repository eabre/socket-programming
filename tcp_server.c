#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int x = 0;
    char server_message[256] = { "do you want to set or get" };
    char command_from_client[256];
    int server_socket;
    int client_socket;

    server_socket = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in server_address;
    server_address.sin_family =AF_INET;
    server_address.sin_port =htons(9002);
    server_address.sin_addr.s_addr= INADDR_ANY;

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    listen(server_socket, 5);

    client_socket = accept(server_socket, NULL, NULL);
    recv(client_socket, &command_from_client, sizeof (command_from_client),0 );
    printf("\nRequest: %s\t\n", command_from_client);

    send(client_socket, "OK", sizeof("OK"), 0);

//    recv(client_socket,&command_from_client, sizeof (command_from_client),0 );
//    printf("\n new x is %s", command_from_client);

    close(server_socket);

    return 0;
}
