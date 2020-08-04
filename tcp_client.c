#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int network_socket;
    char x[256];
    char server_response[256];
    char send_to_server[256] = { "SET" };

    network_socket = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in server_address;
    server_address.sin_family =AF_INET;
    server_address.sin_port =htons(9002);
    server_address.sin_addr.s_addr= INADDR_ANY;

    int connection_status = connect( network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (connection_status == -1) {
        printf(" There was an error making a connection to the remote socket \n\n");
    }

    //send(network_socket, send_to_server, sizeof (send_to_server),0);

    scanf("%s", x);
    printf("%s", x);
    if (strcmp(x,"SET")) {
        printf("Sending Data: %s\n", send_to_server);
        send(network_socket, send_to_server, sizeof (send_to_server),0);
    }
    else {
        printf("Error scanf() !!!\n");
        exit(1);
    }

    recv(network_socket, &server_response, sizeof(server_response), 0);
    printf(" Response: %s\n", server_response);

    close(network_socket);

    return 0;
}
