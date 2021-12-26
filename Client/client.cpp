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
            ShowMainMenu();
            int choice = GetUserChoice();
            switch(choice){
                case 0:
                    cout << "Program ended. Please, wait..." << endl;
                    isRunning = false;
                    break;

                case 1:
                    
            }
        }
    }
    return 0;
}

/**
 * @brief Get username and password from user.
 * 
 * @return string Formatted string.
 */
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

/**
 * @brief Show main menu and related options to user.
 * 
 */
void ShowMainMenu(){
    cout << "MAIN MENU" << endl;
    cout << "1. Create new record;" << endl;
    cout << "2. Search student's record;" << endl;
    cout << "3. Show student's record;" << endl;
    cout << "0. Exit." << endl;
}

/**
 * @brief Get and validate user's choice.
 * 
 * @return int Validate choice.
 */
int GetUserChoice(){
    bool isValid = false;
    int choice;
    while(!isValid){
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice <= 3 && choice >= 0){
            isValid = true;
        }else{
            cout << "Choice not allowed. Please, try again..." << endl;
        }
    }
    return choice;
}