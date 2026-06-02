
//common headers
#include <iostream>
#include <string>
#include <csignal>
#include <cstring>

//socket headers
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

//function for server setup

int serverSetup(int port){
    int socketFd = socket(AF_INET,SOCK_STREAM,0);
    if(socketFd < 0){
        std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
        perror("socket");
        return -1;
    }
    else {
        std::cout << "Socket created successfully." << std::endl;
    
    }
    std::cout << "Creating server socket address variable..." << std::endl;
    sockaddr_in serverAddress;

    std::cout << "Initializing server address structure..." << std::endl;
    serverAddress.sin_family = AF_INET;

    std::cout << "Setting server to accept connections on any interface..." << std::endl;
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    std::cout << "Setting server port to " << port << "..." << std::endl;
    serverAddress.sin_port = htons(port);

    std::cout << "Binding socket to address and port..." << std::endl;
    if (bind(socketFd, (sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){

        std::cerr << "Error binding socket: " << strerror(errno) << std::endl;
        perror("bind");
        close(socketFd);
        return -1;

    }
    else {
        std::cout << "Socket bound successfully." << std::endl;
    }
    std::cout << "Setting socket to listen..." << std::endl;
    if (listen(socketFd, 10) < 0){
        std::cerr << "Error listening on socket: " << strerror(errno) << std::endl;
        perror("listen");
        close(socketFd);
        return -1;
    }
    else {
        std::cout << "Socket is now listening." << std::endl;
    }
    return socketFd;
}

int acceptConnection(int socketFd){
    std::cout << "Waiting for incoming connections..." << std::endl;
    sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);
    int clientSocketFd = accept(socketFd, (sockaddr*)&clientAddress, &clientAddressLen);
    if (clientSocketFd < 0){
        std::cerr << "Error accepting connection: " << strerror(errno) << std::endl;
        perror("accept");
        return -1;
    }
    else {
        std::cout << "Connection accepted from " << inet_ntoa(clientAddress.sin_addr) << ":" << ntohs(clientAddress.sin_port) << std::endl;
    }
    return clientSocketFd;
}
