# xtd
[![Tests](https://github.com/jonathantorres/xtd/actions/workflows/tests.yml/badge.svg?branch=master)](https://github.com/jonathantorres/xtd/actions/workflows/tests.yml)

Various utilities and functions that are not available in the standard library

## Installing
The easiest way is to copy the `include/*.hpp` file into your project, update the namespace (if you want to) as you see fit and use it.

## Included Libraries
### string
A few simple string related functions, the functions implemented currently are:
- `trim_whitespace` to trim any whitespace from the right and left of a string
- `trim` to trim any whitespace from the right and left of a string
- `trim_right` to trim any whitespace from the right of a string
- `trim_left` to trim any whitespace from the left of a string
- `to_lower` to convert a string to lowercase
- `to_upper` to convert a string to uppercase
- `starts_with` check if a string starts with another string
- `ends_with` check if a string ends with another string
- `split` split a string into a vector of strings based on a string delimiter
- `join` create a string based on a container of strings joined by a string delimiter
- `contains` check if a string contains another

### cmd
Parser for command line options

## Running tests
Use `cmake` to build and run the tests:
```bash
cmake -B build -S .
cd build
cmake --build .
./string_tests/string_test
```

