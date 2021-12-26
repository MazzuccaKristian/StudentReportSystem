#include <iostream>
#include <string.h>

//TODO: fix include of SocketHandler. Tips: includePath over relative path to file.
#include "./../SocketHandler/SocketHandler.h"

#define BUFFER_SIZE 20

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::getline;

string LoginHandler();

void ShowMainMenu();

int GetUserChoice();