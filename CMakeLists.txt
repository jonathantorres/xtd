cmake_minimum_required(VERSION 3.18.4)
project(cmd
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.1.0 # or later
)

FetchContent_MakeAvailable(Catch2)

include_directories(.)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)
add_subdirectory(tests cmd_tests)

add_executable(cmd_example cmd_example.cpp cmd.hpp)

