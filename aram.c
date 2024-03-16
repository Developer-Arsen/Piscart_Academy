#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

void error(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) 
{
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }   

    char buffer[256];
    int port_number = atoi(argv[2]);
    
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) 
    {
        error("Error opening socket");
    }
    
    struct hostent *server = gethostbyname(argv[1]);

    if (server == NULL) 
    {
        error("Error: No such host\n");
    }

    struct sockaddr_in server_address;
    bzero((char*)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port_number);

    if (connect(sock_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        error("Error connecting to server");
    }

    while (1) 
    {   
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);
        
        int write_num = write(sock_fd, buffer, strlen(buffer));
        
        if (write_num < 0)
        {
            error("Error writing to socket");
        }

        bzero(buffer, 255);
        int read_num = read(sock_fd, buffer, 255);
        if (read_num < 0)
        {
            error("Error reading from socket");
        }   
        printf("%s", buffer);
        int i = strncmp("Bye", buffer, strlen("Bye"));
        if (i == 0) 
        {
            break;
        }
    }
    close(sock_fd);
    return 0;
}