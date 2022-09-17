#include "string.hpp"
#include <catch2/benchmark/catch_benchmark_all.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("benchmarks using a std::string") {
    std::string s1("   this is a string                ");
    std::string s2("this ONE contains numbers 3 4 7575");
    std::string s3("This is a string");

    REQUIRE(string::trim_whitespace(s1) == "this is a string");
    REQUIRE(string::trim(s1) == "this is a string");
    REQUIRE(string::trim_right(s1) == "   this is a string");
    REQUIRE(string::trim_left(s1) == "this is a string                ");
    REQUIRE(string::to_lower(s2) == "this one contains numbers 3 4 7575");
    REQUIRE(string::to_upper(s2) == "THIS ONE CONTAINS NUMBERS 3 4 7575");
    REQUIRE(string::starts_with(s3, "T") == true);
    REQUIRE(string::ends_with(s3, "g") == true);
    REQUIRE(string::contains(s3, "s") == true);

    std::string sp1("one/two/three");
    std::string sp2("/");
    std::vector<std::string> it1 = string::split(sp1, sp2);

    REQUIRE(it1.size() == 3);
    REQUIRE(it1[0] == "one");
    REQUIRE(it1[1] == "two");
    REQUIRE(it1[2] == "three");

    std::vector<std::string> v1 = {"a", "b", "c"};

    REQUIRE(string::join<std::vector<std::string>>(v1, ",") == "a,b,c");

    BENCHMARK("trim_whitespace") { return string::trim_whitespace(s1); };
    BENCHMARK("trim") { return string::trim(s1); };
    BENCHMARK("trim_right") { return string::trim_right(s1); };
    BENCHMARK("trim_left") { return string::trim_left(s1); };
    BENCHMARK("to_lower") { return string::to_lower(s2); };
    BENCHMARK("to_upper") { return string::to_upper(s2); };
    BENCHMARK("split") { return string::split(sp1, sp2); };
    BENCHMARK("starts_with") { return string::starts_with(s3, "T"); };
    BENCHMARK("ends_with") { return string::ends_with(s3, "g"); };
    BENCHMARK("contains") { return string::contains(s3, "s"); };
    BENCHMARK("join") {
        return string::join<std::vector<std::string>>(v1, ",");
    };
}
