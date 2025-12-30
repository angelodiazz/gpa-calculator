#include "GPACalculator.h"
#include "CourseFileIO.h"
#include "Input.h"
#include <iostream>
#include <iomanip>

static void printSummary(const GPACalculator& calc, double bonus, double cap) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- GPA Summary ---\n";
    std::cout << "Courses: " << calc.courses().size() << "\n";
    std::cout << "Credits Attempted: " << calc.creditsAttempted() << "\n";
    std::cout << "Unweighted GPA: " << calc.unweightedGPA() << "\n";
    std::cout << "Weighted GPA: " << calc.weightedGPA(bonus, cap) << "\n";
}

int main() {
    GPACalculator calc;

    const double bonus = 0.5; // simple default honors/AP bonus
    const double cap = 4.0;

    std::cout << "GPA Calculator (C++)\n";
    std::cout << "Calculates weighted and unweighted GPA with validation + CSV file support.\n\n";

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1) Add course\n";
        std::cout << "2) Load courses from CSV\n";
        std::cout << "3) Save courses to CSV\n";
        std::cout << "4) View GPA summary\n";
        std::cout << "5) Exit\n";

        int choice = Input::promptInt("Choose (1-5): ", 1, 5);

        if (choice == 1) {
            Course c;
            c.name = Input::promptLine("Course name: ");
            c.credits = Input::promptDouble("Credits: ", 0.0, 30.0);
            c.letterGrade = Input::promptGrade("Letter grade (A, A-, B+, ... F): ");
            c.weighted = Input::promptYesNo("Weighted course (Honors/AP)?");

            std::string err;
            if (!calc.addCourse(c, err)) {
                std::cout << "Error: " << err << "\n";
            } else {
                std::cout << "Added.\n";
            }
        } else if (choice == 2) {
            std::string file = Input::promptLine("CSV filename to load: ");
            std::vector<Course> loaded;
            std::string err;

            if (!CourseFileIO::loadCSV(file, loaded, err)) {
                std::cout << "Load failed: " << err << "\n";
                continue;
            }

            // Add to calculator with validation
            bool ok = true;
            for (const auto& c : loaded) {
                std::string addErr;
                if (!calc.addCourse(c, addErr)) {
                    std::cout << "Invalid record found while loading: " << addErr << "\n";
                    ok = false;
                    break;
                }
            }

            if (ok) std::cout << "Loaded " << loaded.size() << " course(s).\n";
        } else if (choice == 3) {
            std::string file = Input::promptLine("CSV filename to save: ");
            std::string err;

            if (!CourseFileIO::saveCSV(file, calc.courses(), err)) {
                std::cout << "Save failed: " << err << "\n";
            } else {
                std::cout << "Saved.\n";
            }
        } else if (choice == 4) {
            if (calc.courses().empty()) {
                std::cout << "No courses yet.\n";
            } else {
                printSummary(calc, bonus, cap);
            }
        } else { // 5
            break;
        }
    }

    std::cout << "\nGoodbye.\n";
    return 0;
}
