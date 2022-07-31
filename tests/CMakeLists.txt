add_executable(cmd_test
    cmd_test.cpp
    ../cmd.hpp
)

target_link_libraries(cmd_test PRIVATE Catch2::Catch2WithMain)

