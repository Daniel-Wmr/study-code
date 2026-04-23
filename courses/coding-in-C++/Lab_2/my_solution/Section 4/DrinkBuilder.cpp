/**
 * @file DrinkBuilder.cpp
 * @brief Lab_2 Section 4
 * 
 * In this project a drink builder has been implemented.
 * First, the user is asked whether he wants to customize the
 * parameters by himself or use default values.
 * If the user chooses to customize the parameters, he will be 
 * asked to enter the values for each parameter (attribute of the object).
 * The user input will be validated during the process, therefore, invalid
 * user inputs will be ignored and the user will be asked to try again.
 * After the validation of all values of the drinks attributes they 
 * will be displayed in the terminal.
 * This project is based on usage and handling of classes and I/O.
 */
#include <iostream>
#include <limits>

#include "DrinkBuilder.hpp"

void userInput(InputMode mode, DrinkBuilder& drink)
{
    std::string name;
    int number = 0;
    bool validation = false;
    bool status = false;


    switch (mode)
    {
    case NAME:
        while (!status)
        {
            std::cout << "Enter the name of your customized Drink: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, name);
            if (name.empty())
            {
                std::cout << "You forgot to enter a Name... Please try again." << std::endl;
                continue;
            }
            else
            {
                status = true;
            }
        }
        drink.setName(name);
        break;
    case SUGAR:
        while (!status)
        {
            std::cout << "Set sugar to (int from 0 to 10): ";
            if (!(std::cin >> number))
            {
                std::cout << "Your number is invalid... Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (number < MINIMUM_SUGAR || number > MAXIMUM_SUGAR)
            {
                std::cout << "The entered number for sugar is out of range... Please try again." << std::endl;
                continue;
            }
            
            drink.setSugar(number);
            status = true;
        }
        break;
    case TEMPERATURE:
        while (!status)
        {
            std::cout << "Set your temperature to (int from 1 to 100): ";
            if (!(std::cin >> number))
            {
                std::cout << "Your number is invalid... Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (number < MINIMUM_TEMPERATURE || number > MAXIMUM_TEMPERATURE)
            {
                std::cout << "The entered temperature is out of range... Please try again." << std::endl;
                continue;
            }
            
            drink.setTemperature(number);
            status = true;
            }
        break;
    case WITHMILK:
        while (!status)
        {
            std::cout << "Should your drink contain milk? (1/0 for Yes/No): ";
            if (!(std::cin >> validation))
            {
                std::cout << "Your input is invalid... Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            drink.setWithMilk(validation);
            status = true;
        }
        break;
    default:
        drink.setName(DEFAULT_NAME).setSugar(DEFAULT_SUGAR).setTemperature(DEFAULT_TEMPERATURE).setWithMilk(DEFAULT_WITH_MILK);
        break;
    }
}

bool DrinkBuilder::isValid() const
{
    return !this->name.empty() && 
        (this->sugar >= MINIMUM_SUGAR) && 
        (this->sugar <= MAXIMUM_SUGAR) &&
        (this->temperature >= MINIMUM_TEMPERATURE) &&
        (this->temperature <= MAXIMUM_TEMPERATURE);
}

DrinkBuilder& DrinkBuilder::setName(const std::string& name)
{
    this->name = name;
    return *this;
}

DrinkBuilder& DrinkBuilder::setSugar(int sugar)
{
    this->sugar = sugar;
    return *this;
}

DrinkBuilder& DrinkBuilder::setTemperature(int temperature)
{
    this->temperature = temperature;
    return *this;
}

DrinkBuilder& DrinkBuilder::setWithMilk(bool withMilk)
{
    this->withMilk = withMilk;
    return *this;
}

void DrinkBuilder::print() const
{
    std::cout << std::boolalpha;
    std::cout << "\n\nName: " << this->name << std::endl;
    std::cout << "Sugar: " << this->sugar << std::endl;
    std::cout << "Temperature: " << this->temperature << std::endl;
    std::cout << "With Milk: " << this->withMilk << std::endl;
}

bool firstUserPrompt()
{
    int userInput = 0;
    bool status = false;
    
    std::cout << "Would you like to design your drink? Press 1 for YES or 0 for DEFAULT: ";
    while (!status)
    {
        if (!(std::cin >> userInput))
        {
            std::cout << "Your input is invalid... Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        if ((userInput != 0) && (userInput != 1))
        {
            std::cout << "Please enter only 1 or 0." << std::endl;
            continue;
        }

        status = true;
    }
    return (userInput == 1);
}

int main()
{
    DrinkBuilder customDrink;
    
    if (firstUserPrompt())
    {
        userInput(NAME, customDrink);
        userInput(SUGAR, customDrink);
        userInput(TEMPERATURE, customDrink);
        userInput(WITHMILK, customDrink);

        if (!(customDrink.isValid()))
        {
            std::cout << "A problem with your object values has occurred..." << std::endl;
            return -1;
        }
    }
    else
    {
        userInput(DEFAULT, customDrink);
    }

    customDrink.print();

    return 0;
}