#ifndef GPA_CALCULATOR_GPACALCULATOR_H
#define GPA_CALCULATOR_GPACALCULATOR_H
#pragma once
#include "Course.h"
#include <string>
#include <vector>

class GPACalculator {
public:
    // Add course with validation; returns false + error message if invalid.
    bool addCourse(const Course& c, std::string& error);

    // Compute GPAs
    double unweightedGPA() const;
    double weightedGPA(double bonus = 0.5, double cap = 4.0) const;

    double creditsAttempted() const;

    const std::vector<Course>& courses() const { return courses_; }

private:
    std::vector<Course> courses_;
};

#endif //GPA_CALCULATOR_GPACALCULATOR_H