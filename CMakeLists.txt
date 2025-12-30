cmake_minimum_required(VERSION 4.1)
project(gpa_calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gpa_calculator
        src/main.cpp
        src/GradeScale.cpp
        src/GPACalculator.cpp
        src/CourseFileIO.cpp
        src/Input.cpp
)

target_include_directories(gpa_calculator PRIVATE src)
