#include "string.hpp"
#include <catch2/catch_test_macros.hpp>
#include <list>
#include <string>
#include <string_view>
#include <vector>

TEST_CASE("whitespace is trimmed with trim_whitespace()") {
    std::string s1("foo");
    std::string s2(" bar");
    std::string s3("baz ");
    std::string s4(" this ");
    std::string s5("this is a string");
    std::string s6("");

    SECTION("using string lvalues") {
        REQUIRE(xtd::trim_whitespace(s1) == "foo");
        REQUIRE(xtd::trim_whitespace(s2) == "bar");
        REQUIRE(xtd::trim_whitespace(s3) == "baz");
        REQUIRE(xtd::trim_whitespace(s4) == "this");
        REQUIRE(xtd::trim_whitespace(s5) == "this is a string");
        REQUIRE(xtd::trim_whitespace(s6) == "");
    }

    SECTION("using string rvalues") {
        REQUIRE(xtd::trim_whitespace(std::string("foo")) == "foo");
        REQUIRE(xtd::trim_whitespace(std::string(" bar")) == "bar");
        REQUIRE(xtd::trim_whitespace(std::string("baz ")) == "baz");
        REQUIRE(xtd::trim_whitespace(std::string(" this ")) == "this");
        REQUIRE(xtd::trim_whitespace(std::string("this is a string")) ==
                "this is a string");
        REQUIRE(xtd::trim_whitespace(
                    std::string("   this   is another string    ")) ==
                "this   is another string");
        REQUIRE(xtd::trim_whitespace(std::string("")) == "");
    }

    SECTION("using string constants") {
        REQUIRE(xtd::trim_whitespace("foo") == "foo");
        REQUIRE(xtd::trim_whitespace(" bar") == "bar");
        REQUIRE(xtd::trim_whitespace("baz ") == "baz");
        REQUIRE(xtd::trim_whitespace(" this ") == "this");
        REQUIRE(xtd::trim_whitespace("this is a string") == "this is a string");
        REQUIRE(xtd::trim_whitespace("   this   is another string    ") ==
                "this   is another string");
        REQUIRE(xtd::trim_whitespace("") == "");
    }

    SECTION("using string views") {
        std::string_view sv1("foo");
        std::string_view sv2(" bar");
        std::string_view sv3("baz ");
        std::string_view sv4(" this ");
        std::string_view sv5("this is a string");
        std::string_view sv6("");

        REQUIRE(xtd::trim_whitespace(sv1) == "foo");
        REQUIRE(xtd::trim_whitespace(sv2) == "bar");
        REQUIRE(xtd::trim_whitespace(sv3) == "baz");
        REQUIRE(xtd::trim_whitespace(sv4) == "this");
        REQUIRE(xtd::trim_whitespace(sv5) == "this is a string");
        REQUIRE(xtd::trim_whitespace(sv6) == "");
    }
}

TEST_CASE("whitespace is trimmed with trim()") {
    std::string s1("foo");
    std::string s2(" bar");
    std::string s3("baz ");
    std::string s4(" this ");
    std::string s5("this is a string");
    std::string s6("");

    SECTION("using string lvalues") {
        REQUIRE(xtd::trim_whitespace(s1) == "foo");
        REQUIRE(xtd::trim_whitespace(s2) == "bar");
        REQUIRE(xtd::trim_whitespace(s3) == "baz");
        REQUIRE(xtd::trim_whitespace(s4) == "this");
        REQUIRE(xtd::trim_whitespace(s5) == "this is a string");
        REQUIRE(xtd::trim_whitespace(s6) == "");
    }

    SECTION("using string rvalues") {
        REQUIRE(xtd::trim_whitespace(std::string("foo")) == "foo");
        REQUIRE(xtd::trim_whitespace(std::string(" bar")) == "bar");
        REQUIRE(xtd::trim_whitespace(std::string("baz ")) == "baz");
        REQUIRE(xtd::trim_whitespace(std::string(" this ")) == "this");
        REQUIRE(xtd::trim_whitespace(std::string("this is a string")) ==
                "this is a string");
        REQUIRE(xtd::trim_whitespace(
                    std::string("   this   is another string    ")) ==
                "this   is another string");
        REQUIRE(xtd::trim_whitespace(std::string("")) == "");
    }

    SECTION("using string constants") {
        REQUIRE(xtd::trim_whitespace("foo") == "foo");
        REQUIRE(xtd::trim_whitespace(" bar") == "bar");
        REQUIRE(xtd::trim_whitespace("baz ") == "baz");
        REQUIRE(xtd::trim_whitespace(" this ") == "this");
        REQUIRE(xtd::trim_whitespace("this is a string") == "this is a string");
        REQUIRE(xtd::trim_whitespace("   this   is another string    ") ==
                "this   is another string");
        REQUIRE(xtd::trim_whitespace("") == "");
    }

    SECTION("using string views") {
        std::string_view sv1("foo");
        std::string_view sv2(" bar");
        std::string_view sv3("baz ");
        std::string_view sv4(" this ");
        std::string_view sv5("this is a string");
        std::string_view sv6("");

        REQUIRE(xtd::trim_whitespace(sv1) == "foo");
        REQUIRE(xtd::trim_whitespace(sv2) == "bar");
        REQUIRE(xtd::trim_whitespace(sv3) == "baz");
        REQUIRE(xtd::trim_whitespace(sv4) == "this");
        REQUIRE(xtd::trim_whitespace(sv5) == "this is a string");
        REQUIRE(xtd::trim_whitespace(sv6) == "");
    }
}

TEST_CASE("right whitespace is trimmed with trim_right()") {
    std::string s1("foo");
    std::string s2(" bar");
    std::string s3("baz ");
    std::string s4(" this ");
    std::string s5("this is a string");
    std::string s6("");

    SECTION("using string lvalues") {
        REQUIRE(xtd::trim_right(s1) == "foo");
        REQUIRE(xtd::trim_right(s2) == " bar");
        REQUIRE(xtd::trim_right(s3) == "baz");
        REQUIRE(xtd::trim_right(s4) == " this");
        REQUIRE(xtd::trim_right(s5) == "this is a string");
        REQUIRE(xtd::trim_right(s6) == "");
    }

    SECTION("using string rvalues") {
        REQUIRE(xtd::trim_right(std::string("foo")) == "foo");
        REQUIRE(xtd::trim_right(std::string(" bar")) == " bar");
        REQUIRE(xtd::trim_right(std::string("baz ")) == "baz");
        REQUIRE(xtd::trim_right(std::string(" this ")) == " this");
        REQUIRE(xtd::trim_right(std::string("this is a string")) ==
                "this is a string");
        REQUIRE(xtd::trim_right(std::string("")) == "");
    }

    SECTION("using string constants") {
        REQUIRE(xtd::trim_right("foo") == "foo");
        REQUIRE(xtd::trim_right(" bar") == " bar");
        REQUIRE(xtd::trim_right("baz ") == "baz");
        REQUIRE(xtd::trim_right(" this ") == " this");
        REQUIRE(xtd::trim_right("this is a string") == "this is a string");
        REQUIRE(xtd::trim_right("") == "");
    }

    SECTION("using string views") {
        std::string_view sv1("foo");
        std::string_view sv2(" bar");
        std::string_view sv3("baz ");
        std::string_view sv4(" this ");
        std::string_view sv5("this is a string");
        std::string_view sv6("");

        REQUIRE(xtd::trim_right(sv1) == "foo");
        REQUIRE(xtd::trim_right(sv2) == " bar");
        REQUIRE(xtd::trim_right(sv3) == "baz");
        REQUIRE(xtd::trim_right(sv4) == " this");
        REQUIRE(xtd::trim_right(sv5) == "this is a string");
        REQUIRE(xtd::trim_right(sv6) == "");
    }
}

TEST_CASE("left whitespace is trimmed with trim_left()") {
    std::string s1("foo");
    std::string s2(" bar");
    std::string s3("baz ");
    std::string s4(" this ");
    std::string s5("this is a string");
    std::string s6("");

    SECTION("using string lvalues") {
        REQUIRE(xtd::trim_left(s1) == "foo");
        REQUIRE(xtd::trim_left(s2) == "bar");
        REQUIRE(xtd::trim_left(s3) == "baz ");
        REQUIRE(xtd::trim_left(s4) == "this ");
        REQUIRE(xtd::trim_left(s5) == "this is a string");
        REQUIRE(xtd::trim_left(s6) == "");
    }

    SECTION("using string rvalues") {
        REQUIRE(xtd::trim_left(std::string("foo")) == "foo");
        REQUIRE(xtd::trim_left(std::string(" bar")) == "bar");
        REQUIRE(xtd::trim_left(std::string("baz ")) == "baz ");
        REQUIRE(xtd::trim_left(std::string(" this ")) == "this ");
        REQUIRE(xtd::trim_left(std::string("this is a string")) ==
                "this is a string");
        REQUIRE(xtd::trim_left(std::string("")) == "");
    }

    SECTION("using string constants") {
        REQUIRE(xtd::trim_left("foo") == "foo");
        REQUIRE(xtd::trim_left(" bar") == "bar");
        REQUIRE(xtd::trim_left("baz ") == "baz ");
        REQUIRE(xtd::trim_left(" this ") == "this ");
        REQUIRE(xtd::trim_left("this is a string") == "this is a string");
        REQUIRE(xtd::trim_left("") == "");
    }

    SECTION("using string views") {
        std::string_view sv1("foo");
        std::string_view sv2(" bar");
        std::string_view sv3("baz ");
        std::string_view sv4(" this ");
        std::string_view sv5("this is a string");
        std::string_view sv6("");

        REQUIRE(xtd::trim_left(sv1) == "foo");
        REQUIRE(xtd::trim_left(sv2) == "bar");
        REQUIRE(xtd::trim_left(sv3) == "baz ");
        REQUIRE(xtd::trim_left(sv4) == "this ");
        REQUIRE(xtd::trim_left(sv5) == "this is a string");
        REQUIRE(xtd::trim_left(sv6) == "");
    }
}

TEST_CASE("string is converted to lower case") {
    std::string s1("foo");
    std::string s2("FOO");
    std::string s3("Jonathan");
    std::string s4("THIS iS aNoTHer STRINg");
    std::string s5("this ONE contains numbers 3 4 7575");

    SECTION("using string lvalues") {
        REQUIRE(xtd::to_lower(s1) == "foo");
        REQUIRE(xtd::to_lower(s2) == "foo");
        REQUIRE(xtd::to_lower(s3) == "jonathan");
        REQUIRE(xtd::to_lower(s4) == "this is another string");
        REQUIRE(xtd::to_lower(s5) == "this one contains numbers 3 4 7575");
    }

    SECTION("using string rvalues") {
        REQUIRE(xtd::to_lower(std::string("foo")) == "foo");
        REQUIRE(xtd::to_lower(std::string("FOO")) == "foo");
        REQUIRE(xtd::to_lower(std::string("Jonathan")) == "jonathan");
        REQUIRE(xtd::to_lower(std::string("THIS iS aNoTHer STRINg")) ==
                "this is another string");
        REQUIRE(
            xtd::to_lower(std::string("this ONE contains numbers 3 4 7575")) ==
            "this one contains numbers 3 4 7575");
    }

    SECTION("using string constants") {
        REQUIRE(xtd::to_lower("foo") == "foo");
        REQUIRE(xtd::to_lower("FOO") == "foo");
        REQUIRE(xtd::to_lower("Jonathan") == "jonathan");
        REQUIRE(xtd::to_lower("THIS iS aNoTHer STRINg") ==
                "this is another string");
        REQUIRE(xtd::to_lower("this ONE contains numbers 3 4 7575") ==
                "this one contains numbers 3 4 7575");
    }

    SECTION("using string views") {
        std::string_view sv1("foo");
        std::string_view sv2("FOO");
        std::string_view sv3("Jonathan");
        std::string_view sv4("THIS iS aNoTHer STRINg");
        std::string_view sv5("this ONE contains numbers 3 4 7575");

        REQUIRE(xtd::to_lower(sv1) == "foo");
        REQUIRE(xtd::to_lower(sv2) == "foo");
        REQUIRE(xtd::to_lower(sv3) == "jonathan");
        REQUIRE(xtd::to_lower(sv4) == "this is another string");
        REQUIRE(xtd::to_lower(sv5) == "this one contains numbers 3 4 7575");
    }
}

TEST_CASE("string is converted to upper case") {
    std::string s1("foo");
    std::string s2("FOO");
    std::string s3("Jonathan");
    std::string s4("THIS iS aNoTHer STRINg");
    std::string s5("this ONE contains numbers 3 4 7575");

    SECTION("using string lvalues") {
        REQUIRE(xtd::to_upper(s1) == "FOO");
        REQUIRE(xtd::to_upper(s2) == "FOO");
        REQUIRE(xtd::to_upper(s3) == "JONATHAN");
        REQUIRE(xtd::to_upper(s4) == "THIS IS ANOTHER STRING");
        REQUIRE(xtd::to_upper(s5) == "THIS ONE CONTAINS NUMBERS 3 4 7575");
    }

    SECTION("using string rvalues") {
        REQUIRE(xtd::to_upper(std::string("foo")) == "FOO");
        REQUIRE(xtd::to_upper(std::string("FOO")) == "FOO");
        REQUIRE(xtd::to_upper(std::string("Jonathan")) == "JONATHAN");
        REQUIRE(xtd::to_upper(std::string("THIS iS aNoTHer STRINg")) ==
                "THIS IS ANOTHER STRING");
        REQUIRE(
            xtd::to_upper(std::string("this ONE contains numbers 3 4 7575")) ==
            "THIS ONE CONTAINS NUMBERS 3 4 7575");
    }

    SECTION("using string constants") {
        REQUIRE(xtd::to_upper("foo") == "FOO");
        REQUIRE(xtd::to_upper("FOO") == "FOO");
        REQUIRE(xtd::to_upper("Jonathan") == "JONATHAN");
        REQUIRE(xtd::to_upper("THIS iS aNoTHer STRINg") ==
                "THIS IS ANOTHER STRING");
        REQUIRE(xtd::to_upper("this ONE contains numbers 3 4 7575") ==
                "THIS ONE CONTAINS NUMBERS 3 4 7575");
    }

    SECTION("using string views") {
        std::string_view sv1("foo");
        std::string_view sv2("FOO");
        std::string_view sv3("Jonathan");
        std::string_view sv4("THIS iS aNoTHer STRINg");
        std::string_view sv5("this ONE contains numbers 3 4 7575");

        REQUIRE(xtd::to_upper(sv1) == "FOO");
        REQUIRE(xtd::to_upper(sv2) == "FOO");
        REQUIRE(xtd::to_upper(sv3) == "JONATHAN");
        REQUIRE(xtd::to_upper(sv4) == "THIS IS ANOTHER STRING");
        REQUIRE(xtd::to_upper(sv5) == "THIS ONE CONTAINS NUMBERS 3 4 7575");
    }
}

TEST_CASE("string is split into a vector of strings") {
    std::vector<std::string> it1 =
        xtd::split(std::string("one/two/three"), std::string("/"));

    REQUIRE(it1.size() == 3);
    REQUIRE(it1[0] == "one");
    REQUIRE(it1[1] == "two");
    REQUIRE(it1[2] == "three");

    std::vector<std::string> it2 =
        xtd::split(std::string("a.b.c"), std::string("."));

    REQUIRE(it2.size() == 3);
    REQUIRE(it2[0] == "a");
    REQUIRE(it2[1] == "b");
    REQUIRE(it2[2] == "c");

    std::vector<std::string> it3 =
        xtd::split(std::string("a-b-c"), std::string(""));

    REQUIRE(it3.size() == 1);
    REQUIRE(it3[0] == "a-b-c");
}

TEST_CASE("a string starts with another") {
    std::string s1 = "This is a string";
    std::string_view sv1 = "This is a string";

    REQUIRE(xtd::starts_with(s1, "T") == true);
    REQUIRE(xtd::starts_with(s1, "This") == true);
    REQUIRE(xtd::starts_with(s1, "Thou") == false);
    REQUIRE(xtd::starts_with(s1, "") == false);
    REQUIRE(xtd::starts_with(s1, "this") == false);
    REQUIRE(xtd::starts_with(s1, "string") == false);

    REQUIRE(xtd::starts_with(sv1, "T") == true);
    REQUIRE(xtd::starts_with(sv1, "This") == true);
    REQUIRE(xtd::starts_with(sv1, "Thou") == false);
    REQUIRE(xtd::starts_with(sv1, "") == false);
    REQUIRE(xtd::starts_with(sv1, "this") == false);
    REQUIRE(xtd::starts_with(sv1, "string") == false);
}

TEST_CASE("a string ends with another") {
    std::string s1 = "This is a message";
    std::string_view sv1 = "This is a message";

    REQUIRE(xtd::ends_with(s1, "e") == true);
    REQUIRE(xtd::ends_with(s1, "message") == true);
    REQUIRE(xtd::ends_with(s1, "something") == false);
    REQUIRE(xtd::ends_with(s1, "") == false);
    REQUIRE(xtd::ends_with(s1, "Message") == false);
    REQUIRE(xtd::ends_with(s1, "another") == false);

    REQUIRE(xtd::ends_with(sv1, "e") == true);
    REQUIRE(xtd::ends_with(sv1, "message") == true);
    REQUIRE(xtd::ends_with(sv1, "something") == false);
    REQUIRE(xtd::ends_with(sv1, "") == false);
    REQUIRE(xtd::ends_with(sv1, "Message") == false);
    REQUIRE(xtd::ends_with(sv1, "another") == false);
}

TEST_CASE("a string contains another") {
    std::string s1 = "A basic string";
    std::string_view sv1 = "A basic string";

    REQUIRE(xtd::contains(s1, "s") == true);
    REQUIRE(xtd::contains(s1, "basic") == true);
    REQUIRE(xtd::contains(s1, "string") == true);
    REQUIRE(xtd::contains(s1, "something") == false);
    REQUIRE(xtd::contains(s1, "") == false);
    REQUIRE(xtd::contains(s1, "Basic") == false);

    REQUIRE(xtd::contains(sv1, "s") == true);
    REQUIRE(xtd::contains(sv1, "basic") == true);
    REQUIRE(xtd::contains(sv1, "string") == true);
    REQUIRE(xtd::contains(sv1, "something") == false);
    REQUIRE(xtd::contains(sv1, "") == false);
    REQUIRE(xtd::contains(sv1, "Basic") == false);
}

TEST_CASE("vector of strings is joined into a string") {
    std::vector<std::string> v1 = {"a", "b", "c"};
    std::vector<std::string> v2 = {"one", "two", "three", "four"};

    REQUIRE(xtd::join<std::vector<std::string>>(v1, ",") == "a,b,c");
    REQUIRE(xtd::join(v2, "--") == "one--two--three--four");
}

TEST_CASE("linked list of strings is joined into a string") {
    std::list<std::string> l1 = {"a", "b", "c"};
    std::list<std::string> l2 = {"one", "two", "three", "four"};

    REQUIRE(xtd::join<std::list<std::string>>(l1, ",") == "a,b,c");
    REQUIRE(xtd::join(l2, "--") == "one--two--three--four");
}
