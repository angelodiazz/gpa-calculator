#include "Input.h"
#include "GradeScale.h"
#include <iostream>
#include <limits>

static void clearLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Input::promptInt(const std::string& msg, int minVal, int maxVal) {
    while (true) {
        std::cout << msg;
        int x;
        if (!(std::cin >> x)) {
            std::cin.clear();
            clearLine();
            std::cout << "Invalid input. Enter a whole number.\n";
            continue;
        }
        clearLine();
        if (x < minVal || x > maxVal) {
            std::cout << "Enter a value between " << minVal << " and " << maxVal << ".\n";
            continue;
        }
        return x;
    }
}

double Input::promptDouble(const std::string& msg, double minExclusive, double maxInclusive) {
    while (true) {
        std::cout << msg;
        double x;
        if (!(std::cin >> x)) {
            std::cin.clear();
            clearLine();
            std::cout << "Invalid input. Enter a number.\n";
            continue;
        }
        clearLine();
        if (!(x > minExclusive && x <= maxInclusive)) {
            std::cout << "Enter a value > " << minExclusive << " and <= " << maxInclusive << ".\n";
            continue;
        }
        return x;
    }
}

bool Input::promptYesNo(const std::string& msg) {
    while (true) {
        std::cout << msg << " (y/n): ";
        std::string s;
        std::getline(std::cin, s);
        if (s.empty()) continue;

        char c = static_cast<char>(std::tolower(static_cast<unsigned char>(s[0])));
        if (c == 'y') return true;
        if (c == 'n') return false;

        std::cout << "Please enter y or n.\n";
    }
}

std::string Input::promptLine(const std::string& msg, bool allowEmpty) {
    while (true) {
        std::cout << msg;
        std::string s;
        std::getline(std::cin, s);
        if (allowEmpty || !s.empty()) return s;
        std::cout << "Input cannot be empty.\n";
    }
}

std::string Input::promptGrade(const std::string& msg) {
    while (true) {
        std::cout << msg;
        std::string g;
        std::getline(std::cin, g);

        double pts = 0.0;
        if (!GradeScale::letterToPoints(g, pts)) {
            std::cout << "Invalid grade. Examples: A, A-, B+, C, D-, F\n";
            continue;
        }
        return g;
    }
}
