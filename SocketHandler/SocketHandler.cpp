#include "SocketHandler.h"

int SocketSetup(){
    int newSocket;
    struct sockaddr_in destinationAddres;
    // socket creation: IPv4, UDP, IP protocol
    if((newSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("SOCKET CREATION");
        exit(EXIT_FAILURE);
    }
    // setup for destination
    destinationAddres.sin_family = AF_INET;
    destinationAddres.sin_port = htons(PORT);
    destinationAddres.sin_addr.s_addr = INADDR_ANY;
    if((inet_pton(AF_INET, HOST_IP, &destinationAddres.sin_addr)) < 0){
        perror("HOST SETUP");
        exit(EXIT_FAILURE);
    }
    // connection
    if(connect(newSocket, (struct sockaddr*)&destinationAddres, sizeof(destinationAddres)) < 0){
        perror("CONNECTION");
        exit(EXIT_FAILURE);
    }
    return newSocket;
}