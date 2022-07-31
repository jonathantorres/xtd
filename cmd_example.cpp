#include "cmd.hpp"

int main(int argc, char **argv) {
    cmd::Command c{argc, argv}; // parse args

    // -f
    c.add_flag('f', fval, "Help message");

    // --foo
    c.add_flag("foo", fval, "Help message");

    // -f or --foo
    c.add_flag("f,foo", fval, "Help message");

    // -f value
    // -f=value
    // --foo value
    // --foo=value
    c.add_option("f,foo", fval, "Help message");

    // prints a nice formatted string of all the options
    c.get_help();
    c.print_help();

    // get all the arguments to the program (not flags)
    // $ myprog one two three
    std::vector<std::string> args = c.get_args();

    return 0;
}
