#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "string.hpp"
#include <string>

TEST_CASE("whitespace is trimmed from a string") {
    std::string s1("foo");
    std::string s2(" bar");
    std::string s3("baz ");
    std::string s4(" this ");
    std::string s5("this is a string");
    std::string s6("");

    REQUIRE(string::trim_whitespace(s1) == "foo");
    REQUIRE(string::trim_whitespace(s2) == "bar");
    REQUIRE(string::trim_whitespace(s3) == "baz");
    REQUIRE(string::trim_whitespace(s4) == "this");
    REQUIRE(string::trim_whitespace(s5) == "this is a string");
    REQUIRE(string::trim_whitespace(s6) == "");
}

TEST_CASE("right whitespace is trimmed from a string") {
    std::string s1("foo");
    std::string s2(" bar");
    std::string s3("baz ");
    std::string s4(" this ");
    std::string s5("this is a string");
    std::string s6("");

    REQUIRE(string::trim_right(s1) == "foo");
    REQUIRE(string::trim_right(s2) == " bar");
    REQUIRE(string::trim_right(s3) == "baz");
    REQUIRE(string::trim_right(s4) == " this");
    REQUIRE(string::trim_right(s5) == "this is a string");
    REQUIRE(string::trim_right(s6) == "");
}

TEST_CASE("left whitespace is trimmed from a string") {
    std::string s1("foo");
    std::string s2(" bar");
    std::string s3("baz ");
    std::string s4(" this ");
    std::string s5("this is a string");
    std::string s6("");

    REQUIRE(string::trim_left(s1) == "foo");
    REQUIRE(string::trim_left(s2) == "bar");
    REQUIRE(string::trim_left(s3) == "baz ");
    REQUIRE(string::trim_left(s4) == "this ");
    REQUIRE(string::trim_left(s5) == "this is a string");
    REQUIRE(string::trim_left(s6) == "");
}

TEST_CASE("string is converted to lower case") {
    std::string s1("foo");
    std::string s2("FOO");
    std::string s3("Jonathan");
    std::string s4("THIS iS aNoTHer STRINg");
    std::string s5("this ONE contains numbers 3 4 7575");

    REQUIRE(string::to_lower(s1) == "foo");
    REQUIRE(string::to_lower(s2) == "foo");
    REQUIRE(string::to_lower(s3) == "jonathan");
    REQUIRE(string::to_lower(s4) == "this is another string");
    REQUIRE(string::to_lower(s5) == "this one contains numbers 3 4 7575");
}

TEST_CASE("string is converted to upper case") {
    std::string s1("foo");
    std::string s2("FOO");
    std::string s3("Jonathan");
    std::string s4("THIS iS aNoTHer STRINg");
    std::string s5("this ONE contains numbers 3 4 7575");

    REQUIRE(string::to_upper(s1) == "FOO");
    REQUIRE(string::to_upper(s2) == "FOO");
    REQUIRE(string::to_upper(s3) == "JONATHAN");
    REQUIRE(string::to_upper(s4) == "THIS IS ANOTHER STRING");
    REQUIRE(string::to_upper(s5) == "THIS ONE CONTAINS NUMBERS 3 4 7575");
}
