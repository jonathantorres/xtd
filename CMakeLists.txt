cmake_minimum_required(VERSION 3.13.4)
project(xtd
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

add_library(xtd INTERFACE)
target_include_directories(xtd INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    include(FetchContent)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.1.0 # or later
    )

    if (${CMAKE_VERSION} VERSION_LESS 3.14)
        FetchContent_GetProperties(Catch2)
        if (NOT Catch2_POPULATED)
            FetchContent_Populate(Catch2)
            add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
        endif()
    else()
        FetchContent_MakeAvailable(Catch2)
    endif()

    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
    include_directories(include)
    add_subdirectory(tests xtd_tests)

    add_executable(cmd_example src/cmd_example.cpp include/cmd.hpp)
    add_executable(daemon_example src/daemon_example.cpp include/daemon.hpp)
endif()

