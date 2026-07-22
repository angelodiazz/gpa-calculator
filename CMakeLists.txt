cmake_minimum_required(VERSION 3.20)

project(GPACalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(gpa_calculator
        src/main.cpp
        src/GradeScale.cpp
        src/GPACalculator.cpp
        src/CourseFileIO.cpp
        src/Input.cpp
)

target_include_directories(gpa_calculator
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)