# GPA Calculator (C++17)

A high-integrity C++ application designed to calculate weighted and unweighted academic performance metrics. This project emphasizes **Defensive Programming**, **Robust File I/O**, and **Modular Systems Architecture**.

---

## 🚀 Key Engineering Features
* **Data Integrity & Validation**: Implemented a centralized `Input` namespace and `GradeScale` utility to enforce strict data constraints, preventing malformed inputs (e.g., negative credits or invalid grades) from corrupting calculations.
* **Persistent Storage**: Engineered a custom CSV parser in `CourseFileIO` that supports full data persistence, allowing users to export and import course histories with comprehensive error reporting during the parsing lifecycle.
* **Weighted Logic Engine**: Developed a flexible calculation engine in `GPACalculator` capable of handling Honors/AP weight distributions with customizable bonuses and GPA caps.
* **Modular Architecture**: Adhered to a strict **Separation of Concerns (SoC)** model, decoupling the calculation logic from the UI (CLI) and data persistence layers.

---

## 🛡 Security & Defensive Design
* **Type Safety**: Utilized `std::stod` with comprehensive `try-catch` blocks to handle conversion errors during file ingestion, protecting the application from crashing on malformed external data.
* **Input Sanitization**: Integrated string normalization logic (`trim` and `toupper`) to sanitize user input before it reaches the core logic, ensuring system resilience against casing and spacing inconsistencies.
* **State Protection**: Used `const` member functions and pass-by-reference-to-const to ensure memory efficiency and protect internal data states from unintended modification.

---

## 🛠 Tech Stack
| Category | Technologies |
| :--- | :--- |
| **Language** | C++17 |
| **Data Management** | STL Containers (`std::vector`, `std::unordered_map`) |
| **Build System** | CMake |
| **Development Tools** | CLion / Git |

---

## 📂 Project Structure
```text
gpa-calculator/
├── src/
│   ├── main.cpp            # Application Entry Point
│   ├── GPACalculator.h/cpp # Core GPA Logic & State
│   ├── Course.h            # Data Models (Structs)
│   ├── CourseFileIO.h/cpp  # CSV Persistence Layer
│   ├── GradeScale.h/cpp    # Validation & Normalization Logic
│   ├── Input.h/cpp         # Defensive User Input Handling
├── CMakeLists.txt          # Build Configuration
├── .gitignore              # Version Control Optimization

```

## 🚀 Build & Run
Ensure you have **CMake 3.10+** and a **C++17** compatible compiler installed.

### 1. Configure and Build
```bash
# Generate build files
cmake -S . -B build

# Compile the project
cmake --build build

```
### 1. Execute the Application
```bash
# Run the binary
./build/gpa_calculator
