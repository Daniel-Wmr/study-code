#ifndef GRADEREPORTFORMATTER_HPP
#define GRADEREPORTFORMATTER_HPP

#define MIN_SCORE 0
#define MAX_SCORE 100

typedef enum Score_Mode
{
    HOMEWORK,
    MIDTERM,
    FINALEXAM
}Score_Mode;

/**
 * @brief Asks for user input (score-numbers) and validates it
 * 
 * According to the active mode (Homework, Midterm, FinalExam) a prompt
 * will be printed in the terminal, asking the user to enter the scores.
 * Afterwards, the users input will be validated by cheking whether the
 * input contains junk-numbers or the inputs number is out of range.
 * The numbers will be stored in the respective variables.
 * @param[in] score is a reference to the score the user is entering the number for
 * @param[in] mode is an enum to vary the prompt message according to the active mode
 * @return is a boolean to verrify whether the user input is valid or not
 */
bool user_input(int& score, Score_Mode mode);

/**
 * @brief Reads the Students Data via user input
 * 
 * Prompt messages will be printed so the user can enter the students
 * name and scores in homework, midterm and final exam.
 * To ask for user input and verify the input the user_input() function will be called.
 * If the users input is invalid, he has to try again.
 * @param[in] name is a reference to the string storaging the students name
 * @param[in] homework is a reference to the students homework-score
 * @param[in] midterm is a reference to the students midterm-score
 * @param[in] finalExam is a reference to the students finalExam-score  
 */
void readStudentData(std::string& name,
                    uint_fast8_t& homework,
                    uint_fast8_t& midterm,
                    uint_fast8_t& finalExam);

/**
 * @brief Calculates the final Grade and investigates the letter
 * 
 * According to the weighting of the scores, the final grade will be calculated.
 * Afterwards, the grade-letter will be determined based on the final grade.
 * @param[in] homework is the value of the students homework-score
 * @param[in] midterm is the value of the students midterm-score
 * @param[in] finalExam is the value of the student finalExam-score
 * @param[in] finalGrade is a reference to the initialized finalGrade-score
 * @param[in] letterGrade is a reference to the initialized letterGrade-string
 * @return no return - void
 */
void calculateGrade(uint_fast8_t homework,
                    uint_fast8_t midterm,
                    uint_fast8_t finalExam,
                    uint_fast8_t& finalGrade,
                    std::string& letterGrade);

/**
 * @brief Prints the students final report in the terminal
 * 
 * This function creates a formatted output of the students report data.
 * Furthermore, the status of the report will be determined, which declares
 * whether the student passed, passed conditionally or failed.
 * @param[in] name is a reference to the students name string
 * @param[in] homework is the value of the students homework-score
 * @param[in] midterm is the value of the students midterm-score
 * @param[in] finalExam is the value of the students finalExam-score
 * @param[in] finalGrade is the value of the calculated students final grade
 * @param[in] letterGrade is the string for the letter-grade
 */
void printReport(std::string& name,
                 uint_fast8_t homework,
                 uint_fast8_t midterm,
                 uint_fast8_t finalExam,
                 uint_fast8_t finalGrade,
                 std::string& letterGrade);

#endif