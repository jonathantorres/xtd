# daemon
[![Build](https://github.com/jonathantorres/daemon/actions/workflows/build.yml/badge.svg)](https://github.com/jonathantorres/daemon/actions/workflows/build.yml)

Daemonize a process


## Installing
The easiest way is to copy the `include/daemon.h` file into your project, update the namespace as you see fit and use it.

## Usage
The only function on the header file is `daemonize`, call this function at the point in which to want to daemonize (run as a daemon) your UNIX process.


