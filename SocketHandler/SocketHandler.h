#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>

using std::perror;

#define PORT 8080
#define HOST_IP "127.0.0.1"
#define CONNECTIONS 10

int ClientSocketSetup();

int ServerSocketSetup();