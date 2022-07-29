#ifndef string_hpp
#define string_hpp

#include <cctype>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

namespace string {

std::string trim_whitespace(const std::string &s);
std::string trim_right(const std::string &s);
std::string trim_left(const std::string &s);
std::string to_lower(const std::string &s);
std::string to_upper(const std::string &s);
bool starts_with(const std::string &s1, const std::string &s2);
bool ends_with(const std::string &s1, const std::string &s2);
std::vector<std::string> split(const std::string &s, const std::string &delim);

template <typename Container>
std::string join(const Container &contents, const std::string &delim);

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

std::vector<std::string> split(const std::string &s, const std::string &delim) {
    std::vector<std::string> res;

    if (s.size() == 0) {
        return res;
    }

    if (delim.size() == 0) {
        res.push_back(s);

        return res;
    }

    std::string_view str(s.begin(), s.end());
    std::string_view sv_delim(delim.begin(), delim.end());

    for (const auto &word : std::views::split(str, sv_delim)) {
        std::string w;

        for (const auto &c : word) {
            w.push_back(c);
        }
        res.push_back(w);
    }

    return res;
}

template <typename Container>
std::string join(const Container &contents, const std::string &delim) {
    if (contents.size() == 0) {
        return "";
    }

    std::string res;

    for (const auto &item : contents) {
        res.append(item);
        res.append(delim);
    }

    res.erase(res.size() - delim.size(), delim.size());

    return res;
}

bool starts_with(const std::string &s1, const std::string &s2) {
    if (s1.size() == 0 || s2.size() == 0) {
        return false;
    }

    auto n = s1.find(s2);

    if (n == std::string::npos) {
        return false;
    }

    if (n == 0) {
        return true;
    }

    return false;
}

bool ends_with(const std::string &s1, const std::string &s2) {
    if (s1.size() == 0 || s2.size() == 0) {
        return false;
    }

    auto n = s1.rfind(s2);

    if (n == std::string::npos) {
        return false;
    }

    if (n == (s1.size() - s2.size())) {
        return true;
    }

    return false;
}

} // namespace string
#endif
