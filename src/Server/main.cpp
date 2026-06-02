#include "serverSetup.h"
#include "getUserInput.h"

int main(){
    int serverPort = getPortNumber();
    int serverSocketFD = serverSetup(serverPort);
    while (true){
        //server loop
        acceptConnection(serverSocketFD);

    }
    return 0;

}