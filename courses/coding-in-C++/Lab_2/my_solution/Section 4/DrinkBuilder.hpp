#ifndef DRINK_BUILDER_HPP
#define DRINK_BUILDER_HPP

#include <string>

inline const std::string DEFAULT_NAME = "Drinky Drink";
constexpr int DEFAULT_SUGAR = 2;
constexpr int DEFAULT_TEMPERATURE = 15;
constexpr bool DEFAULT_WITH_MILK = true;

constexpr int MINIMUM_SUGAR = 0;
constexpr int MAXIMUM_SUGAR = 10;
constexpr int MINIMUM_TEMPERATURE = 1;
constexpr int MAXIMUM_TEMPERATURE = 100;


typedef enum InputMode
{
    NAME,
    SUGAR,
    TEMPERATURE,
    WITHMILK,
    DEFAULT
}InputMode;

class DrinkBuilder
{
private:
    std::string name;
    int sugar;
    int temperature;
    bool withMilk;

public:
    /**
     * @brief Constructor for default values
     */
    DrinkBuilder()
        : name(DEFAULT_NAME), 
        sugar(DEFAULT_SUGAR), 
        temperature(DEFAULT_TEMPERATURE), 
        withMilk(DEFAULT_WITH_MILK)
    {}

    /**
     * @brief Validation of the objects attributes
     * 
     * Validates the objects attributes, whethere they are valid or not.
     * @return boolean
     */
    bool isValid() const;

    /**
     * @brief Set the objects attribute name
     * 
     * Sets the name for the drinks name via string parameter and
     * stores it in the objects name-attribute.
     * The functions returns a reference to the object itself, which 
     * enables method chaining.
     * @param[in] name is a string
     * @return DrinkBuilder& is a reference to the object itself.
     */
    DrinkBuilder& setName(const std::string& name);

    /**
     * @brief Set the objects attribute sugar
     * 
     * Sets the sugar value of the object (drink) to a
     * passed integer.
     * The function returns a reference to the object itself, which 
     * enables method chaining.
     * @param[in] sugar is an integer and is the passed value
     * @return DrinkBuilder& is a reference to the object itself
     */
    DrinkBuilder& setSugar(int sugar);

    /**
     * @brief Set the objects attribute tempereature
     * 
     * Sets the temperature value of the object (drink) to a
     * passed integer.
     * The function returns a reference to the object itself, which 
     * enables method chaining.
     * @param[in] temperature is an integer and is the passed value
     * @return DrinkBuilder& is a reference to the object itself
     */
    DrinkBuilder& setTemperature(int temperature);

    /**
     * @brief Set the objects attribute withMilk
     * 
     * Sets the withMilk-bool of the object (drink) to a
     * passed boolean.
     * The function returns a reference to the object itself, which 
     * enables method chaining.
     * @param[in] withMilk is an boolean and is the passed value
     * @return DrinkBuilder& is a reference to the object itself
     */
    DrinkBuilder& setWithMilk(bool withMilk);

    /**
     * @brief Prints the objects attributes and their values in the terminal
     */
    void print() const;
};

/**
 * @brief Asks the user for an input and validates it
 * 
 * Depending on the passed mode the suitable prompt will be diesplayed
 * in the terminal. After the user enters his input it will be validated.
 * If the validation fails, the user has to retry.
 * If the validation succeeds, the userInput will be stored
 * in the suitable objects attribute depending on the passed mode.
 * @param[in] mode is from the enum InputMode and determines the functions behaviour
 * @param[in] drink is a reference to the object itself, so the objects attributes can be updated.  
 */
void userInput(InputMode mode, DrinkBuilder& drink);

/**
 * @brief First User Prompt after running the programm
 * 
 * In the first user prompt the user will be asked, whether he wants to customize
 * the objects (drinks) attributes or use default values.
 * The user input will be validated in this function and determines the
 * value of the returned boolean.
 * @return boolean, which determines whether the programm uses customized or default values for the attributes.
 */
bool firstUserPrompt();

#endif 