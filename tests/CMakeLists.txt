add_executable(string_test
    string_test.cpp
    ../include/string.hpp
)
add_executable(string_benchmarks
    string_benchmarks.cpp
    ../include/string.hpp
)

add_custom_command(TARGET string_test
    POST_BUILD
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/string_test
    VERBATIM
)
add_custom_command(TARGET string_benchmarks
    POST_BUILD
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/string_benchmarks
    VERBATIM
)

target_link_libraries(string_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(string_benchmarks PRIVATE Catch2::Catch2WithMain)

