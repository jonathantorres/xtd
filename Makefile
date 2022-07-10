CPPFLAGS = g++ -std=c++20 -Wall -Wextra -Wpedantic
STRING_TEST := string_test

# Run tests
.PHONY: all
all: $(STRING_TEST)

# compile tests
$(STRING_TEST):%: %.cpp
	$(CPPFLAGS) $^ -o $@
	./$@

.PHONY: clean
clean:
	rm -f ./*.o *.hpp.gch $(STRING_TEST)
