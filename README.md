# string
A few simple header-only string related functions

## Installing
The easiest way is to copy the string.h file into your project, update the namespace as you see fit and use it. The functions implemented currently are:
- `trim_whitespace` to trim any whitespace from the right and left of a string
- `trim_right` to trim any whitespace from the right of a string
- `trim_left` to trim any whitespace from the left of a string
- `to_lower` to convert a string to lowercase
- `to_upper` to convert a string to uppercase
- `starts_with` check if a string starts with another string
- `ends_with` check if a string ends with another string
- `split` split a string into a vector of strings based on a string delimiter
- `join` create a string based on a container of strings joined by a string delimiter
- `contains` check if a string contains another

## Running tests
Use `cmake` to build and run the tests:
```bash
cmake -B build -S .
cd build
cmake --build .
./string_tests/string_test
```

