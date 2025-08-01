#include "pch.h"
#include <iostream>
#include "ExamGrader.h"
#include "WorldSeries.h"
#include "TicTacToe.h"

int main() {
    int choice = 0;
    do {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Exam Grader\n";
        std::cout << "2. World Series Lookup\n";
        std::cout << "3. Tic-Tac-Toe Game\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: runExamGrader(); break;
        case 2: runWorldSeriesLookup(); break;
        case 3: runTicTacToe(); break;
        case 4: std::cout << "Goodbye!\n"; break;
        default: std::cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
