#include "GPACalculator.h"
#include "GPACalculator.h"
#include "GradeScale.h"
#include <limits>

bool GPACalculator::addCourse(const Course& c, std::string& error) {
    if (c.name.empty()) {
        error = "Course name cannot be empty.";
        return false;
    }
    if (!(c.credits > 0.0) || c.credits > 30.0) {
        error = "Credits must be > 0 and reasonable (<= 30).";
        return false;
    }

    double points = 0.0;
    if (!GradeScale::letterToPoints(c.letterGrade, points)) {
        error = "Invalid grade. Examples: A, A-, B+, C, D-, F";
        return false;
    }

    courses_.push_back(c);
    return true;
}

double GPACalculator::creditsAttempted() const {
    double total = 0.0;
    for (const auto& c : courses_) total += c.credits;
    return total;
}

double GPACalculator::unweightedGPA() const {
    double qualityPoints = 0.0;
    double credits = 0.0;

    for (const auto& c : courses_) {
        double pts = 0.0;
        if (!GradeScale::letterToPoints(c.letterGrade, pts)) continue; // shouldn't happen
        qualityPoints += pts * c.credits;
        credits += c.credits;
    }

    if (credits <= 0.0) return 0.0;
    return qualityPoints / credits;
}

double GPACalculator::weightedGPA(double bonus, double cap) const {
    double qualityPoints = 0.0;
    double credits = 0.0;

    for (const auto& c : courses_) {
        double pts = 0.0;
        if (!GradeScale::letterToPoints(c.letterGrade, pts)) continue;

        if (c.weighted) pts += bonus;
        if (pts > cap) pts = cap;

        qualityPoints += pts * c.credits;
        credits += c.credits;
    }

    if (credits <= 0.0) return 0.0;
    return qualityPoints / credits;
}
