cmake_minimum_required(VERSION 3.18.4)
project(string
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

include_directories(.)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)
add_subdirectory(tests string_tests)

