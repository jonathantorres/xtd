#include "string.hpp"
#include <catch2/benchmark/catch_benchmark_all.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("benchmarks using a std::string") {
    std::string s1("   this is a string                ");
    std::string s2("this ONE contains numbers 3 4 7575");
    std::string s3("This is a string");

    REQUIRE(xtd::trim_whitespace(s1) == "this is a string");
    REQUIRE(xtd::trim(s1) == "this is a string");
    REQUIRE(xtd::trim_right(s1) == "   this is a string");
    REQUIRE(xtd::trim_left(s1) == "this is a string                ");
    REQUIRE(xtd::to_lower(s2) == "this one contains numbers 3 4 7575");
    REQUIRE(xtd::to_upper(s2) == "THIS ONE CONTAINS NUMBERS 3 4 7575");
    REQUIRE(xtd::starts_with(s3, "T") == true);
    REQUIRE(xtd::ends_with(s3, "g") == true);
    REQUIRE(xtd::contains(s3, "s") == true);

    std::string sp1("one/two/three");
    std::string sp2("/");
    std::vector<std::string> it1 = xtd::split(sp1, sp2);

    REQUIRE(it1.size() == 3);
    REQUIRE(it1[0] == "one");
    REQUIRE(it1[1] == "two");
    REQUIRE(it1[2] == "three");

    std::vector<std::string> v1 = {"a", "b", "c"};

    REQUIRE(xtd::join<std::vector<std::string>>(v1, ",") == "a,b,c");

    BENCHMARK("trim_whitespace") { return xtd::trim_whitespace(s1); };
    BENCHMARK("trim") { return xtd::trim(s1); };
    BENCHMARK("trim_right") { return xtd::trim_right(s1); };
    BENCHMARK("trim_left") { return xtd::trim_left(s1); };
    BENCHMARK("to_lower") { return xtd::to_lower(s2); };
    BENCHMARK("to_upper") { return xtd::to_upper(s2); };
    BENCHMARK("split") { return xtd::split(sp1, sp2); };
    BENCHMARK("starts_with") { return xtd::starts_with(s3, "T"); };
    BENCHMARK("ends_with") { return xtd::ends_with(s3, "g"); };
    BENCHMARK("contains") { return xtd::contains(s3, "s"); };
    BENCHMARK("join") { return xtd::join<std::vector<std::string>>(v1, ","); };
}
