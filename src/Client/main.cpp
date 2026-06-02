#include "clientSetup.h"
#include "getUserInput.h"
#include <iostream>

int main() {
    std::cout << "Welcome to the ChatLI Client!" << std::endl;

    std::string serverIp = getIPAddress();
    int port = getPortNumber();
    int socketFd = clientSetup(serverIp, port);
    if (socketFd < 0) {
        std::cerr << "Failed to set up client. Exiting." << std::endl;
        return 1;
    }
}