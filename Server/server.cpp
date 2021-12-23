#include "server.h"

int main()
{
    bool isRunning = true;
    int serverSocket, newSocket;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;

    char socketBuffer[BUFFER_SIZE] = {0};

    ArchiveSetup();

    serverSocket = ServerSocketSetup();
    addr_size = sizeof(serverStorage);

    while (isRunning)
    {
        newSocket = accept(serverSocket, (struct sockaddr *)&serverStorage, &addr_size);

        if (recv(newSocket, socketBuffer, BUFFER_SIZE, 0) < 0)
        {
            perror("RECV");
        }
        else
        {
            char option = socketBuffer[0];
            if(option == 'x'){
                string convertedBuffer = socketBuffer;
                string loginData = convertedBuffer.substr(convertedBuffer.find_first_of("|") + 1);
                if(LoginUser(loginData)){
                    // Here if the user is in archive. Login OK
                }else{
                    // Here if the user entered wrong credentials. Login must be repeated.
                }
            }
        }
    }
}

/**
 * @brief Setup for archive file. Creation only, no initalization.
 * 
 */
void ArchiveSetup()
{
    ifstream records(RECORDS);
    if (records.is_open())
    {
        // File exists. No further setup needed.
        records.close();
    }
    else
    {
        // File doesn't exists. Creation needed.
        ofstream recordsSetup(RECORDS);
        if (recordsSetup.is_open())
        {
            recordsSetup.close();
        }
    }
}

/**
 * @brief Handle user's login with archive file.
 * 
 * @param data Username and password concatenated.
 * @return true if these values have been found in archive
 * @return false 
 */
bool LoginUser(string data){
    string username, password;
    bool found = false;
    username = data.substr(0, data.find_first_of("|"));
    password = data.substr(data.find_first_of("|") + 1);
    if(SearchInArchive("username:", username)){
        if(SearchInArchive("password:", password)){
            found = true;
        }
    }
    return found;
}

/**
 * @brief Search if a key-value pair exists in archive.
 * 
 * @param key wanted key
 * @param value wanted value
 * @return true if key-value pair exists
 * @return false 
 */
bool SearchInArchive(string key, string value){
    bool found = false;
    ifstream records(RECORDS);
    if(records.is_open()){
        string readedKey, readedValue;
        while(records >> readedKey >> readedValue){
            if(readedKey.compare(key) == 0){
                if(readedValue.compare(value) == 0){
                    found = true;
                }
            }
        }
        records.close();
    }
    return found;
}