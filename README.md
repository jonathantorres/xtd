# xtd
[![Build and Tests](https://github.com/jonathantorres/xtd/actions/workflows/tests.yml/badge.svg?branch=master)](https://github.com/jonathantorres/xtd/actions/workflows/tests.yml)

Various utilities and functions that are not available in the standard library

## Installing
The easiest way is to copy the `include/*.hpp` file into your project, update the namespace (if you want to) as you see fit and use it.

## Included Libraries
### string
A few simple string related functions, the functions implemented currently are:
- `trim_whitespace` to trim any whitespace from the right and left of a string
- `trim` to trim any whitespace from the right and left of a string
- `trim_right` to trim any whitespace from the right of a string
- `trim_left` to trim any whitespace from the left of a string
- `to_lower` to convert a string to lowercase
- `to_upper` to convert a string to uppercase
- `starts_with` check if a string starts with another string
- `ends_with` check if a string ends with another string
- `split` split a string into a vector of strings based on a string delimiter
- `join` create a string based on a container of strings joined by a string delimiter
- `contains` check if a string contains another

### cmd
Parser for command line options

### daemon
Daemonize a process. There are two functions, `daemonize` which will daemonize the process and `daemon_is_running` which will check for a lock file to make sure the process is not run more than once at the same time.

```cpp
// "cmd" is the name of your program
void daemonize(std::string cmd);

// "cmd" is the name of your program and "lockfile_path" is the location
// of where you wish to store the lockfile with the process id
// it returns true if the process is already running and false otherwise
bool daemon_is_running(std::string cmd, std::string lockfile_path);
```

## Running tests
Use `cmake` to build and run the tests:
```bash
cmake -B build -S .
cd build
cmake --build .
```

