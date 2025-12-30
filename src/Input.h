#ifndef GPA_CALCULATOR_INPUT_H
#define GPA_CALCULATOR_INPUT_H
#pragma once
#include <string>

namespace Input {
    int promptInt(const std::string& msg, int minVal, int maxVal);
    double promptDouble(const std::string& msg, double minExclusive, double maxInclusive);
    bool promptYesNo(const std::string& msg);
    std::string promptLine(const std::string& msg, bool allowEmpty = false);
    std::string promptGrade(const std::string& msg);
}

#endif //GPA_CALCULATOR_INPUT_H