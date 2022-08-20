add_executable(string_test
    string_test.cpp
    ../include/string.hpp
)

add_custom_command(TARGET string_test
    POST_BUILD
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/string_test
    VERBATIM
)

target_link_libraries(string_test PRIVATE Catch2::Catch2WithMain)

