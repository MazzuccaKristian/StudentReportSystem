#include "client.h"

int main(){
    bool isRunning = true;
    bool isLoggedIn = false;
    int userOption;
    int clientSocket;

    clientSocket = SocketSetup();

    while(isRunning){
        if(!isLoggedIn){
            // Here if the user isn't logged in.
            string user = LoginHandler();
            //TODO: at this point, "user" must be sent to server for authentication.
        }else{
            //TODO: starting now: show main menu; get user's choice; run related option.
        }
    }
}

string LoginHandler(){
    string username, password, userData;
    cout << "Please, enter your credentials." << endl;
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your password: ";
    getline(cin, password);
    userData = username + "|" + password;
    return userData;
}