/**
 * @file GradeReportFormatter.cpp
 * @brief Lab_1 Section 4
 * 
 * In this project a grade-report-formatter has been implemented.
 * The students data (containing name and several scores) is enterd
 * by the user, after several user prompts occured.
 * The grade-report-formatter calculates the final results based on 
 * the entered data and determines the letter-grade.
 * Afterwards, the entered and calculated data is formatted and displayed
 * in the terminal.
 * Furthermore, the final report contains the students status information
 * whether he passed, passed conditionally or failed.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>
#include <limits>

#include "GradeReportFormatter.hpp"

static void printLine();

bool user_input(int& score, Score_Mode mode)
{   
    switch (mode)
    {
        case HOMEWORK:
            std::cout << "Homework score: ";
            break;
        case MIDTERM:
            std::cout << "Midterm score: ";
            break;
        default:
            std::cout << "Final exam score: ";
    }

    if (!(std::cin >> score))
    {
        std::cout << "You entered an invalid number. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    if ((score < MIN_SCORE) || (score > MAX_SCORE))
    {
        std::cout << "Your entered number is out of scope. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;
} 

void readStudentData(std::string& name,
                    uint_fast8_t& homework,
                    uint_fast8_t& midterm,
                    uint_fast8_t& finalExam)
{
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);

    int temp = 0;

    while (!(user_input(temp, HOMEWORK)));
    homework = static_cast<uint_fast8_t>(temp);
    while (!(user_input(temp, MIDTERM)));
    midterm = static_cast<uint_fast8_t>(temp); 
    while (!(user_input(temp, FINALEXAM)));
    finalExam = static_cast<uint_fast8_t>(temp);

}

void calculateGrade(uint_fast8_t homework,
                    uint_fast8_t midterm,
                    uint_fast8_t finalExam,
                    uint_fast8_t& finalGrade,
                    std::string& letterGrade)
{
    finalGrade = homework*0.4 + midterm*0.25 + finalExam*0.35;

    if (finalGrade >= 90)
    {
        letterGrade = "A";
    }
    else if (finalGrade >= 80)
    {
        letterGrade = "B";
    }
    else if (finalGrade >= 70)
    {
        letterGrade = "C";
    }
    else if (finalGrade >= 60)
    {
        letterGrade = "D";
    }
    else if (finalGrade >= 50)
    {
        letterGrade = "E";
    }
    else
    {
        letterGrade = "F";
    }
}

static void printLine()
{
    std::cout << std::setfill('-') << std::setw(30) << "-" << std::endl;
}

void printReport(std::string& name,
                 uint_fast8_t homework,
                 uint_fast8_t midterm,
                 uint_fast8_t finalExam,
                 uint_fast8_t finalGrade,
                 std::string& letterGrade)
{
    printLine();
    std::cout << "Student Report" << std::endl;
    printLine();

    std::cout << "Name: " << name << std::endl << std::endl;

    std::cout << "Scores" << std::endl;
    printLine();

    std::cout << std::setfill(' ') << std::setw(15) << std::left << "Homework" << std::right << ": ";
    std::cout << static_cast<int>(homework) << std::endl;
    std::cout << std::setw(15) << std::left << "Midterm" << std::right << ": ";
    std::cout << static_cast<int>(midterm) << std::endl;
    std::cout << std::setw(15) << std::left << "Final Exam" << std::right << ": ";
    std::cout << static_cast<int>(finalExam) << std::endl << std::endl;
    std::cout << std::setw(15) << std::left << "Final Grade" << std::right << ": ";
    std::cout << static_cast<int>(finalGrade) << std::endl;
    std::cout << std::setw(15) << std::left << "Letter" << std::right << ": ";
    std::cout << letterGrade << std::endl;
    
    std::cout << std::setw(15) << std::left << "Status" << std::right << ": ";
    if(letterGrade == "A" || letterGrade == "B" || letterGrade == "C")
    {
        std::cout << "Pass" << std::endl;
    }
    else if (letterGrade == "D" || letterGrade == "E")
    {
        std::cout << "Conditional Pass" << std::endl;
    }
    else
    {
        std::cout << "Fail" << std::endl;
    }

    printLine();
}


int main()
{
    std::string name;
    uint_fast8_t homework = 0;
    uint_fast8_t midterm = 0;
    uint_fast8_t finalExam = 0;
    uint_fast8_t finalGrade = 0;
    std::string letterGrade;

    readStudentData(name, homework, midterm, finalExam);

    calculateGrade(homework, midterm, finalExam, finalGrade, letterGrade);

    printReport(name, homework, midterm, finalExam, finalGrade, letterGrade);
    
    return 0;
}