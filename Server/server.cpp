#include "server.h"

int main(){
    bool isRunning = true;

    ArchiveSetup();

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