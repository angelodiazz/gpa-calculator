#ifndef GPA_CALCULATOR_GRADESCALE_H
#define GPA_CALCULATOR_GRADESCALE_H
#pragma once
#include <string>

class GradeScale {
public:
    // Returns true if valid and sets outPoints (4.0 scale). Otherwise false.
    static bool letterToPoints(const std::string& letter, double& outPoints);

    // Normalizes input like " a- " -> "A-"
    static std::string normalizeLetter(std::string s);

private:
    static std::string trim(const std::string& s);
};

#endif //GPA_CALCULATOR_GRADESCALE_H