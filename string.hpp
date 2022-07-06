#ifndef string_hpp
#define string_hpp

#include <cctype>
#include <string>

namespace string {

std::string trim_whitespace(const std::string &s);
std::string trim_right(const std::string &s);
std::string trim_left(const std::string &s);
std::string to_lower(const std::string &s);
std::string to_upper(const std::string &s);

std::string trim_whitespace(const std::string &s) {
    std::string res = trim_left(s);

    return trim_right(res);
}

std::string trim_right(const std::string &s) {
    auto rev_it = s.rbegin();
    while (rev_it.base() != s.begin() && std::isspace(*rev_it)) {
        rev_it++;
    }

    return std::string(s.begin(), rev_it.base());
}

std::string trim_left(const std::string &s) {
    auto it = s.begin();
    while (it != s.end() && std::isspace(*it)) {
        it++;
    }

    return std::string(it, s.end());
}

std::string to_lower(const std::string &s) {
    std::string res;

    for (auto &c : s) {
        int new_char = c;
        if (std::isalpha(c)) {
            new_char = std::tolower(c);
        }
        res.push_back(new_char);
    }

    return res;
}

std::string to_upper(const std::string &s) {
    std::string res;

    for (auto &c : s) {
        int new_char = c;
        if (std::isalpha(c)) {
            new_char = std::toupper(c);
        }
        res.push_back(new_char);
    }

    return res;
}

} // namespace string
#endif
