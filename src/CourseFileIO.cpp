#include "CourseFileIO.h"
#include "CourseFileIO.h"
#include "GradeScale.h"
#include <fstream>
#include <sstream>

static bool parseBool(const std::string& s, bool& out) {
    if (s == "1" || s == "true" || s == "TRUE" || s == "True") { out = true; return true; }
    if (s == "0" || s == "false" || s == "FALSE" || s == "False") { out = false; return true; }
    return false;
}

bool CourseFileIO::saveCSV(const std::string& filename,
                           const std::vector<Course>& courses,
                           std::string& error) {
    std::ofstream out(filename);
    if (!out) {
        error = "Could not open file for writing: " + filename;
        return false;
    }

    out << "name,credits,grade,weighted\n";
    for (const auto& c : courses) {
        out << c.name << ","
            << c.credits << ","
            << GradeScale::normalizeLetter(c.letterGrade) << ","
            << (c.weighted ? "1" : "0") << "\n";
    }

    if (!out) {
        error = "Failed while writing to file: " + filename;
        return false;
    }
    return true;
}

bool CourseFileIO::loadCSV(const std::string& filename,
                           std::vector<Course>& outCourses,
                           std::string& error) {
    std::ifstream in(filename);
    if (!in) {
        error = "Could not open file for reading: " + filename;
        return false;
    }

    outCourses.clear();

    std::string line;
    // header
    if (!std::getline(in, line)) {
        error = "File is empty or unreadable.";
        return false;
    }

    int lineNum = 1;
    while (std::getline(in, line)) {
        ++lineNum;
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string name, creditsStr, gradeStr, weightedStr;

        if (!std::getline(ss, name, ',') ||
            !std::getline(ss, creditsStr, ',') ||
            !std::getline(ss, gradeStr, ',') ||
            !std::getline(ss, weightedStr)) {
            error = "Invalid CSV format on line " + std::to_string(lineNum) + ".";
            return false;
        }

        Course c;
        c.name = name;

        try {
            c.credits = std::stod(creditsStr);
        } catch (...) {
            error = "Invalid credits on line " + std::to_string(lineNum) + ".";
            return false;
        }

        c.letterGrade = gradeStr;

        bool w = false;
        if (!parseBool(weightedStr, w)) {
            error = "Invalid weighted flag on line " + std::to_string(lineNum) + " (use 1/0).";
            return false;
        }
        c.weighted = w;

        // Validate grade early to prevent bad data
        double pts = 0.0;
        if (!GradeScale::letterToPoints(c.letterGrade, pts)) {
            error = "Invalid grade on line " + std::to_string(lineNum) + ".";
            return false;
        }
        if (!(c.credits > 0.0)) {
            error = "Credits must be > 0 on line " + std::to_string(lineNum) + ".";
            return false;
        }

        outCourses.push_back(c);
    }

    return true;
}
