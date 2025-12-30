# GPA Calculator (C++)

A C++ application that calculates **weighted and unweighted GPAs (4.0 scale)** using validated user input and **CSV-based file handling**. This project was built to demonstrate clean program structure, defensive input validation, and modular C++ design.

## Features
- Calculates **unweighted GPA** on a standard **4.0 scale**
- Supports **weighted GPA** for Honors/AP-style courses
- **Robust input validation** for credits and letter grades
- **CSV file import/export** to save and load course data
- Clear **separation of concerns** across GPA logic, input handling, and file I/O

## Design Overview
The program is structured into focused components:
- **GPA calculation logic** is isolated in a dedicated calculator class
- **Grade parsing and validation** are handled independently
- **File I/O** is separated using CSV read/write utilities
- **User input handling** is centralized to prevent invalid data entry

This design improves accuracy, maintainability, and extensibility.

## Project Structure
gpa-calculator/
├── src/
│   ├── main.cpp
│   ├── GPACalculator.h
│   ├── GPACalculator.cpp
│   ├── Course.h
│   ├── CourseFileIO.h
│   ├── CourseFileIO.cpp
│   ├── GradeScale.h
│   ├── GradeScale.cpp
│   ├── Input.h
│   └── Input.cpp
├── CMakeLists.txt
├── .gitignore
└── README.md


## Build & Run
This project uses **CMake** and **C++17**.

```bash
cmake -S . -B build
cmake --build build
./build/gpa_calculator
