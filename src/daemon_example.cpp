#include "daemon.hpp"
#include <iostream>

int main(void) {
    std::cout << "Starting process.." << '\n';

    net::daemonize();

    return 0;
}
