#include "GradeScale.h"
#include "GradeScale.h"
#include <cctype>
#include <algorithm>
#include <unordered_map>

std::string GradeScale::trim(const std::string& s) {
    size_t i = 0;
    while (i < s.size() && std::isspace(static_cast<unsigned char>(s[i]))) ++i;
    size_t j = s.size();
    while (j > i && std::isspace(static_cast<unsigned char>(s[j - 1]))) --j;
    return s.substr(i, j - i);
}

std::string GradeScale::normalizeLetter(std::string s) {
    s = trim(s);
    for (char& ch : s) ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
    s.erase(std::remove_if(s.begin(), s.end(),
                           [](unsigned char c) { return std::isspace(c); }),
            s.end());
    return s;
}

bool GradeScale::letterToPoints(const std::string& letter, double& outPoints) {
    static const std::unordered_map<std::string, double> map = {
        {"A", 4.0}, {"A-", 3.7},
        {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7},
        {"D+", 1.3}, {"D", 1.0}, {"D-", 0.7},
        {"F", 0.0}
    };

    const std::string g = normalizeLetter(letter);
    auto it = map.find(g);
    if (it == map.end()) return false;

    outPoints = it->second;
    return true;
}