#include "daemon.hpp"
#include <iostream>
#include <string>
#include <syslog.h>
#include <unistd.h>

int main(void) {
    std::cout << "Starting process.." << '\n';
    std::string program("net");
    std::string path("/home/jonathan/daemon_test.pid");

    xtd::daemonize(program);

    if (xtd::daemon_is_running(program, path)) {
        syslog(LOG_ERR, "daemon already running");
        std::exit(EXIT_FAILURE);
    }

    sleep(30);

    return 0;
}
