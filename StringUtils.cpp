#include "StringUtils.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

namespace StringUtils {

// Refrenced in Readme
std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept {
    if (start > end) return "";
    if (start > str.length()) start = str.length();
    if (end > str.length() || end == 0) end = str.length();
    return str.substr(start, end - start);
}
// Refrenced in Readme

std::string Capitalize(const std::string &str) noexcept {
    if (str.empty()) return str;
    std::string capitalized = str;
    capitalized[0] = std::toupper(capitalized[0]);
    return capitalized;
}
// Refrenced in Readme

std::string Upper(const std::string &str) noexcept {
    std::string upper_str = str;
    std::transform(upper_str.begin(), upper_str.end(), upper_str.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return upper_str;
}

std::string Lower(const std::string &str) noexcept {
    std::string lower_str = str;
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return lower_str;
}
// Refrenced in Readme

std::string LStrip(const std::string &str) noexcept {
    std::size_t first_not_space = str.find_first_not_of(' ');
    if (first_not_space == std::string::npos) return "";
    return str.substr(first_not_space);
}

std::string RStrip(const std::string &str) noexcept {
    std::size_t last_not_space = str.find_last_not_of(' ');
    if (last_not_space == std::string::npos) return "";
    return str.substr(0, last_not_space + 1);
}

std::string Strip(const std::string &str) noexcept {
    return LStrip(RStrip(str));
}
// Refrenced in Readme

std::string Center(const std::string &str, int width, char fill) noexcept {
    int padding = width - static_cast<int>(str.size());
    if (padding <= 0) return str;
    int pad_left = padding / 2;
    int pad_right = padding - pad_left;
    return std::string(pad_left, fill) + str + std::string(pad_right, fill);
}
// Refrenced in Readme

std::string LJust(const std::string &str, int width, char fill) noexcept {
    int padding = width - static_cast<int>(str.size());
    if (padding <= 0) return str;
    return str + std::string(padding, fill);
}

std::string RJust(const std::string &str, int width, char fill) noexcept {
    int padding = width - static_cast<int>(str.size());
    if (padding <= 0) return str;
    return std::string(padding, fill) + str;
}
// Refrenced in Readme 
std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept {
    std::string result = str;
    std::size_t pos = 0;
    while ((pos = result.find(old, pos)) != std::string::npos) {
        result.replace(pos, old.length(), rep);
        pos += rep.length();
    }
    return result;
}
// Refrenced in Readme

std::vector<std::string> Split(const std::string &str, const std::string &split) noexcept {
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;
    while ((end = str.find(split, start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + split.length();
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
// Refrenced in README
std::string Join(const std::vector<std::string> &vec, const std::string &connector) noexcept {
    std::ostringstream oss;
    if (!vec.empty()) {
        std::copy(vec.begin(), vec.end() - 1, std::ostream_iterator<std::string>(oss, connector.c_str()));
        oss << vec.back();
    }
    return oss.str();

}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept {
    std::string expanded;
    for (char c : str) {
        if (c == '\t') {
            expanded += std::string(tabsize, ' ');
        } else {
            expanded += c;
        }
    }
    return expanded;
}
// Refrenced in read me
int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept {
    const std::size_t len1 = left.size(), len2 = right.size();
    std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

    for (unsigned int i = 0; i <= len1; ++i) d[i][0] = i;
    for (unsigned int j = 0; j <= len2; ++j) d[0][j] = j;

    for (unsigned int i = 1; i <= len1; ++i) {
        for (unsigned int j = 1; j <= len2; ++j) {
            unsigned int cost = (ignorecase ? std::tolower(left[i - 1]) != std::tolower(right[j - 1]) : left[i - 1] != right[j - 1]);
            d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost });
        }
    }
    return d[len1][len2];
}

}  // namespace StringUtils
