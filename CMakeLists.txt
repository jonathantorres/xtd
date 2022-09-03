cmake_minimum_required(VERSION 3.13.4)
project(cmd
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

add_library(cmd INTERFACE)
target_include_directories(cmd INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
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
endif()

