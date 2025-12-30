#ifndef GPA_CALCULATOR_COURSEFILEIO_H
#define GPA_CALCULATOR_COURSEFILEIO_H
#pragma once
#include "Course.h"
#include <string>
#include <vector>

class CourseFileIO {
public:
    // CSV format: name,credits,grade,weighted
    static bool saveCSV(const std::string& filename,
                        const std::vector<Course>& courses,
                        std::string& error);

    static bool loadCSV(const std::string& filename,
                        std::vector<Course>& outCourses,
                        std::string& error);
};

#endif //GPA_CALCULATOR_COURSEFILEIO_H