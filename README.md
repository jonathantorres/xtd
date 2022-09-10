# daemon
[![Build](https://github.com/jonathantorres/daemon/actions/workflows/build.yml/badge.svg)](https://github.com/jonathantorres/daemon/actions/workflows/build.yml)

Daemonize a process

## Installing
The easiest way is to copy the `include/daemon.h` file into your project, update the namespace as you see fit and use it.

## Usage
There are two functions, `daemonize` which will daemonize the process and `daemon_is_running` which will check for a lock file to make sure the process is not ran more than once at the same time.

```cpp
// "cmd" is the name of your program
void daemonize(std::string cmd);

// "cmd" is the name of your program and "lockfile_path" is the location
// of where you wish to store the lockfile with the process id
// it returns true if the process is already running and false otherwise
bool daemon_is_running(std::string cmd, std::string lockfile_path);
```


