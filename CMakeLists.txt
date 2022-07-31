cmake_minimum_required(VERSION 3.18.4)
project(string
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

add_library(string INTERFACE)
target_sources(string INTERFACE string.hpp)
include_directories(.)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    include(FetchContent)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.1.0 # or later
    )

    FetchContent_MakeAvailable(Catch2)

    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
    add_subdirectory(tests string_tests)
endif()

