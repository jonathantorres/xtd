#include "cmd.hpp"
#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char **argv) {
    xtd::command c{argc, argv};
    bool f_val;
    bool foo_val;
    std::string d_val;
    std::string doit_val;

    // -f
    c.add_flag('f', f_val);

    // -foo
    c.add_flag("foo", foo_val);
    c.add_flag(std::string("foo"), foo_val);

    // -d value
    c.add_option('d', d_val);

    // -doit value
    c.add_option("doit", doit_val);

    // parse args
    c.parse();

    std::cout << "f_val=" << f_val << '\n';
    std::cout << "foo_val=" << foo_val << '\n';
    std::cout << "d_val=" << d_val << '\n';
    std::cout << "doit_val=" << doit_val << '\n';
    std::cout << c.unknown_value_found() << '\n';
    std::cout << c.unknown_flag() << '\n';

    return 0;
}
