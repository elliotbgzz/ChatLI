#include <iostream>
#include <string>
static constexpr bool VERBOSE = true;

void log(const std::string& message) {
    if constexpr (VERBOSE) {
        std::cout << message << std::endl;
    }
}
void log_error(const std::string& message) {
    if constexpr (VERBOSE) {
        std::cerr << message << std::endl;
    }
}