#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "string.hpp"
#include <list>
#include <string>
#include <vector>

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

TEST_CASE("string is split into a vector of strings") {
    std::vector<std::string> it1 =
        string::split(std::string("one/two/three"), std::string("/"));

    REQUIRE(it1.size() == 3);
    REQUIRE(it1[0] == "one");
    REQUIRE(it1[1] == "two");
    REQUIRE(it1[2] == "three");

    std::vector<std::string> it2 =
        string::split(std::string("a.b.c"), std::string("."));

    REQUIRE(it2.size() == 3);
    REQUIRE(it2[0] == "a");
    REQUIRE(it2[1] == "b");
    REQUIRE(it2[2] == "c");

    std::vector<std::string> it3 =
        string::split(std::string("a-b-c"), std::string(""));

    REQUIRE(it3.size() == 1);
    REQUIRE(it3[0] == "a-b-c");
}

TEST_CASE("a string starts with another") {
    std::string s1 = "This is a string";

    REQUIRE(string::starts_with(s1, "T") == true);
    REQUIRE(string::starts_with(s1, "This") == true);
    REQUIRE(string::starts_with(s1, "Thou") == false);
    REQUIRE(string::starts_with(s1, "") == false);
    REQUIRE(string::starts_with(s1, "this") == false);
    REQUIRE(string::starts_with(s1, "string") == false);
}

TEST_CASE("a string ends with another") {
    std::string s1 = "This is a message";

    REQUIRE(string::ends_with(s1, "e") == true);
    REQUIRE(string::ends_with(s1, "message") == true);
    REQUIRE(string::ends_with(s1, "something") == false);
    REQUIRE(string::ends_with(s1, "") == false);
    REQUIRE(string::ends_with(s1, "Message") == false);
    REQUIRE(string::ends_with(s1, "another") == false);
}

TEST_CASE("a string contains another") {
    std::string s1 = "A basic string";

    REQUIRE(string::contains(s1, "s") == true);
    REQUIRE(string::contains(s1, "basic") == true);
    REQUIRE(string::contains(s1, "string") == true);
    REQUIRE(string::contains(s1, "something") == false);
    REQUIRE(string::contains(s1, "") == false);
    REQUIRE(string::contains(s1, "Basic") == false);
}

TEST_CASE("vector of strings is joined into a string") {
    std::vector<std::string> v1 = {"a", "b", "c"};
    std::vector<std::string> v2 = {"one", "two", "three", "four"};

    REQUIRE(string::join<std::vector<std::string>>(v1, ",") == "a,b,c");
    REQUIRE(string::join(v2, "--") == "one--two--three--four");
}

TEST_CASE("linked list of strings is joined into a string") {
    std::list<std::string> l1 = {"a", "b", "c"};
    std::list<std::string> l2 = {"one", "two", "three", "four"};

    REQUIRE(string::join<std::list<std::string>>(l1, ",") == "a,b,c");
    REQUIRE(string::join(l2, "--") == "one--two--three--four");
}
