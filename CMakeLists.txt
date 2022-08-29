cmake_minimum_required(VERSION 3.13.4)
project(string
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

add_library(string INTERFACE)
target_include_directories(string INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    include(FetchContent)

    # FetchContent_MakeAvailable macro for cmake versions less than 3.14
    if (${CMAKE_VERSION} VERSION_LESS 3.14)
        macro(FetchContent_MakeAvailable NAME)
            FetchContent_GetProperties(${NAME})
            if (NOT ${NAME}_POPULATED)
                FetchContent_Populate(${NAME})
                add_subdirectory(${${NAME}_SOURCE_DIR} ${${NAME}_BINARY_DIR})
            endif()
        endmacro()
    endif()


    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.1.0 # or later
    )

    FetchContent_MakeAvailable(Catch2)

    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
    include_directories(include)
    add_subdirectory(tests string_tests)
endif()

