add_executable(cmd_test
    cmd_test.cpp
    ../include/cmd.hpp
)

add_custom_command(TARGET cmd_test
    POST_BUILD
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/cmd_test
    VERBATIM
)

target_link_libraries(cmd_test PRIVATE Catch2::Catch2WithMain)

