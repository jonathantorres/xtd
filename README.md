# string
A few simple header-only string related functions

## Installing
The easiest way is to copy the string.h file into your project, update the namespace as you see fit and use it. The functions implemented currently are:
- `trim_whitespace` to trim any whitespace from the right and left of a string
- `trim_right` to trim any whitespace from the right of a string
- `trim_left` to trim any whitespace from the left of a string
- `to_lower` to convert a string to lowercase
- `to_upper` to convert a string to uppercase

All of these functions take a reference to a string a returns a newly created string with the modifications

## Running tests
Use `make` to run all of the tests:
```bash
make
```

