#include "client.h"

int main(){
    bool isRunning = true;
    bool isLoggedIn = false;
    int userOption;
    int clientSocket;
    char responseFromServer[BUFFER_SIZE] = {0};

    // clientSocket = ClientSocketSetup();
    clientSocket = ClientSocketSetup();

    while(isRunning){
        if(!isLoggedIn){
            // Here if the user isn't logged in.
            string user = LoginHandler();
            if(send(clientSocket, user.c_str(), user.length(), 0) == -1){
                // Fail on "send"
                perror("SEND");
            }else{
                if(recv(clientSocket, responseFromServer, BUFFER_SIZE, 0) < 0){
                    perror("RECV");
                }else{
                    if(strcmp(responseFromServer, "true") == 0){
                        // Login OK
                        isLoggedIn = true;
                    }
                }
            }
        }else{
            //TODO: starting now: show main menu; get user's choice; run related option.
            
        }
    }
    return 0;
}

string LoginHandler(){
    string username, password, userData;
    cout << "Please, enter your credentials." << endl;
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your password: ";
    getline(cin, password);
    userData = "x|" + username + "|" + password;
    return userData;
}