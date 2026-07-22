# GPA Calculator

A C++17 command-line application for calculating credit-weighted, weighted, and unweighted GPA values.

The project demonstrates modular C++ design, input validation, grade normalization, Standard Template Library containers, and basic CSV persistence.

## Features

- Add courses interactively
- Validate course names and credit values
- Normalize letter grades
- Convert letter grades to grade points
- Calculate total attempted credits
- Calculate unweighted GPA
- Calculate weighted GPA
- Apply a configurable weighted-course bonus and GPA cap
- Save courses to CSV
- Load courses from CSV
- Report invalid files and malformed values

## Grade Scale

The application supports:

```text
A   A-
B+  B   B-
C+  C   C-
D+  D   D-
F
```

Letter grades are normalized by:

- Removing surrounding whitespace
- Removing internal whitespace
- Converting letters to uppercase

## GPA Calculations

Unweighted GPA is calculated using credit-weighted quality points.

Weighted courses receive a configurable bonus before the configured GPA cap is applied.

The current defaults are:

```text
Weighted-course bonus: 0.5
GPA cap: 4.0
```

These values are defined in `main.cpp` and can be changed for different grading policies.

## CSV Persistence

The CSV format is:

```text
name,credits,grade,weighted
```

Example:

```text
Data Structures,3,A,1
Discrete Mathematics,3,B+,0
```

The current parser uses a simple comma-delimited format.

Course names containing commas are not currently supported. A future version could add quoted-field parsing and escaping.

## Technologies

- C++17
- Standard Template Library
- `std::vector`
- `std::unordered_map`
- File streams
- String streams
- CMake

## Project Structure

```text
gpa-calculator/
├── src/
│   ├── main.cpp
│   ├── Course.h
│   ├── GPACalculator.h
│   ├── GPACalculator.cpp
│   ├── GradeScale.h
│   ├── GradeScale.cpp
│   ├── CourseFileIO.h
│   ├── CourseFileIO.cpp
│   ├── Input.h
│   └── Input.cpp
├── CMakeLists.txt
├── .gitignore
└── README.md
```

## Build

Requirements:

- CMake 3.20 or newer
- A C++17-compatible compiler

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/gpa_calculator
```
