//common headers
#include <iostream>
#include <string>
#include <cstring>

//socket headers
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int clientSetup(const std::string& serverIp, int port) {
    int socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd < 0) {
        std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
        perror("socket");
        return -1;
    }
    else {
        std::cout << "Socket created successfully." << std::endl;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    if (inet_pton(AF_INET, serverIp.c_str(), &serverAddress.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported: " << strerror(errno) << std::endl;
        perror("inet_pton");
        close(socketFd);
        return -1;
    }

    if (connect(socketFd, (sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Connection failed: " << strerror(errno) << std::endl;
        perror("connect");
        close(socketFd);
        return -1;
    }
    else {
        std::cout << "Connected to server successfully." << std::endl;
    }

    return socketFd;
}