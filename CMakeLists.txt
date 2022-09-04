cmake_minimum_required(VERSION 3.13.4)
project(daemon
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

add_library(daemon INTERFACE)
target_include_directories(daemon INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    include_directories(include)
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)

    add_executable(daemon_example src/daemon_example.cpp include/daemon.hpp)
endif()

