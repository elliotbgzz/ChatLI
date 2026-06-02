#include <iostream>
#include <string>
#include <cstdlib>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <system_error>

std::string getIPAddress() {
    while (true) {
        in_addr buffer;
        std::string ipAddress;
        std::cout << "Enter the server IP address in this format x.x.x.x (E to exit): ";
        std::getline(std::cin, ipAddress);
        if (ipAddress.empty()) {
            std::cerr << "IP address cannot be empty. Please enter a valid IP address." << std::endl;
        }
        else if (ipAddress == "E" || ipAddress == "e") {
            std::cout << "Exiting..." << std::endl;
            exit(0);
        }
        else if (inet_pton(AF_INET, ipAddress.c_str(), &buffer) <= 0) {
            std::cerr << "Invalid IP address format. Please enter a valid IP address in the format x.x.x.x." << std::endl;
        }

        else {
            return ipAddress;
        }
    } 
}

int getPortNumber() {
    while (true){
        std::cout << "Enter the port number (1-65535), type E to exit: ";
        std::string input;
        std::getline(std::cin, input);
        if (input == "E" || input == "e") {
            std::cout << "Exiting..." << std::endl;
            exit(0);
        }
        try {
            size_t numericalPortSize;
            int port = std::stoi(input, &numericalPortSize);
            if (numericalPortSize != input.size()) {
                std::cerr << "Invalid input. You entered non-numeric characters." << std::endl;
            } else if (port < 1 || port > 65535) {
                std::cerr << "Invalid port number. Please enter a number between 1 and 65535." << std::endl;
            } else {
                return port;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input. Please enter a valid integer for the port number." << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Port number out of range. Please enter a number between 1 and 65535." << std::endl;
        }
    }
}