#ifndef GPA_CALCULATOR_COURSE_H
#define GPA_CALCULATOR_COURSE_H
#pragma once
#include <string>

struct Course {
    std::string name;
    double credits = 0.0;        // must be > 0
    std::string letterGrade;     // e.g. A, A-, B+, ... F
    bool weighted = false;       // honors/AP style
};


#endif //GPA_CALCULATOR_COURSE_H