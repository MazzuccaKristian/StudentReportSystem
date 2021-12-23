#include "server.h"

int main(){
    bool isRunning = true;
    int serverSocket, newSocket;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;

    char socketBuffer[BUFFER_SIZE] = {0};

    ArchiveSetup();

    serverSocket = ServerSocketSetup();

    addr_size = sizeof(serverStorage);
    newSocket = accept(serverSocket, (struct sockaddr*)&serverStorage, &addr_size);

    if(recv(newSocket, socketBuffer, BUFFER_SIZE, 0) < 0){
        perror("RECV");
    }else{

    }
}

void ArchiveSetup(){
    ifstream records(RECORDS);
    if(records.is_open()){
        // File exists. No further setup needed.
        records.close();
    }else{
        // File doesn't exists. Creation needed.
        ofstream recordsSetup(RECORDS);
        if(recordsSetup.is_open()){
            recordsSetup.close();
        }
    }
}