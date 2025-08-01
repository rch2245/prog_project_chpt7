// ============================================
// Exam Grader Program - Analysis & Design
// ============================================

// Types of Input:
// - File input: CorrectAnswers.txt and StudentAnswers.txt (20 lines each)

// Program Output:
// - List of missed questions with correct vs student answers
// - Total number of missed questions
// - Percentage score
// - Pass/fail message based on 70% threshold

// Algorithm / Tasks:
// 1. Read answer key and student answers into arrays
// 2. Compare arrays and track missed questions
// 3. Calculate percentage of correct answers
// 4. Display detailed report using writeReport()

// Hierarchy Chart:
// runExamGrader()
// - getAnswers()
// - gradeExam()
// - writeReport()

// Pseudocode:
// getAnswers(correctAnswers)
// getAnswers(studentAnswers)
// gradeExam(correctAnswers, studentAnswers, missed, incorrect)
// writeReport(missed, incorrect)




#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int NUM_QUESTIONS = 20;

// Reads exam answers from a file into an array
void getAnswers(const string& filename, char answers[]) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open file: " << filename << endl;
        exit(1);
    }

    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (!(file >> answers[i])) {
            cerr << "Error reading line " << i + 1 << " from " << filename << endl;
            exit(1);
        }
    }

    file.close();
}

// Compares student answers to the correct ones, tracks missed questions
int gradeExam(const char correct[], const char student[], int missed[], char incorrect[][2]) {
    int missedCount = 0;

    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (correct[i] != student[i]) {
            missed[missedCount] = i + 1;             // Question number (1-indexed)
            incorrect[missedCount][0] = correct[i];  // Correct answer
            incorrect[missedCount][1] = student[i];  // Student's answer
            ++missedCount;
        }
    }

    return missedCount;
}

// Displays a full exam report
void writeReport(int missed[], int missedCount, char incorrect[][2]) {
    int correctCount = NUM_QUESTIONS - missedCount;
    double percent = (static_cast<double>(correctCount) / NUM_QUESTIONS) * 100.0;

    cout << "\n--- Exam Report ---\n";

    if (missedCount > 0) {
        cout << left << setw(12) << "Question"
            << setw(20) << "Correct Answer"
            << setw(15) << "Your Answer" << endl;

        for (int i = 0; i < missedCount; ++i) {
            cout << left << setw(12) << missed[i]
                << setw(20) << incorrect[i][0]
                << setw(15) << incorrect[i][1] << endl;
        }
    }
    else {
        cout << "Perfect score! No questions missed.\n";
    }

    cout << "\nTotal Missed: " << missedCount << endl;
    cout << fixed << setprecision(1);
    cout << "Test score: " << percent << "%\n";

    if (percent >= 70.0)
        cout << "You passed the exam.\n";
    else
        cout << "You did not pass the exam.\n";
}


// Main function to run the grading process
void runExamGrader() {
    char correct[NUM_QUESTIONS], student[NUM_QUESTIONS];
    int missed[NUM_QUESTIONS];
    char incorrect[NUM_QUESTIONS][2];

    getAnswers("CorrectAnswers.txt", correct);
    getAnswers("StudentAnswers.txt", student);

    int missedCount = gradeExam(correct, student, missed, incorrect);
    writeReport(missed, missedCount, incorrect);
}
