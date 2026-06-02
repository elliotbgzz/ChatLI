#include <iostream>
#include <string>

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