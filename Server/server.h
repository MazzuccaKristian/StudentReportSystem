#include <fstream>
#include <iostream>
#include <string.h>

#include "./../SocketHandler/SocketHandler.h"

using std::ifstream;
using std::ofstream;
using std::string;

#define RECORDS "records.txt"
#define BUFFER_SIZE 10

void ArchiveSetup();

bool LoginUser(string data);

bool SearchInArchive(string key, string value);