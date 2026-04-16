/**
 * @file AgeValidation.cpp
 * @brief Section 2 of Lab_1
 * 
 * In this project a simple age-validator has been implemented.
 * It takes an user-input, validates it and prints in the terminal
 * whether the age suggests that the person is a senior, an adult or a kid/teenager. 
 * 
 * The user-input will be validated whereby it is checked whether:
 * - the number is not a negative
 * - the number is a realistic age
 * - the input is not junk but a valid number
 */

#include <iostream>
#include <string>
#include <cstdint>
#include <limits>

#include "AgeValidation.hpp"

bool isAdult(uint8_t age)
{
    return (age >=18);
}

bool isSenior(uint8_t age)
{
    return (age >= 65);
}

State validate_state(uint8_t age)
{
    if (isSenior(age))
    {
        return SENIOR;
    }
    else if (isAdult(age))
    {
        return ADULT;
    }
    else
    {
        return CHILD;
    }
}


int main()
{
    int age = 0;
    bool valid_input = false;
    std::string validated_state;

    while(valid_input == false)
    {
        std::cout << "Please enter your age: ";
        if (!(std::cin >> age) || (age < 0) || (age > 125))
        {
            std::cout << "You did not enter a valid number. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        valid_input = true;
    }

    std::cout << "You are " << age << " years old." << std::endl;

    switch (validate_state(static_cast<uint8_t>(age)))
    {
        case SENIOR:
            validated_state = "a senior citizen.";
            break;
        case ADULT:
            validated_state = "an adult.";
            break;
        default:
            validated_state = "still a kid or a teenager.";
    }

    std::cout << "That means that you are " << validated_state << std::endl;
    
    return 0;
}