#ifndef DRINK_BUILDER_HPP
#define DRINK_BUILDER_HPP

#include <string>

const std::string DEFAULT_NAME = "Drinky Drink";
constexpr int DEFAULT_SUGAR = 2;
constexpr int DEFAULT_TEMPERATURE = 15;
constexpr bool DEFAULT_WITH_MILK = true;

constexpr int MINIMUM_SUGAR = 0;
constexpr int MAXIMUM_SUGAR = 10;
constexpr int MINIMUM_TEMPERATURE = 0;
constexpr int MAXIMUM_TEMPERATURE = 100;


typedef enum InputMode
{
    NAME,
    SUGAR,
    TEMPERATURE,
    WITHMILK,

    STRING,
    INTEGER,
    BOOLEAN,
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
    DrinkBuilder()
        : name(DEFAULT_NAME), sugar(DEFAULT_SUGAR), temperature(DEFAULT_TEMPERATURE), withMilk(DEFAULT_WITH_MILK)
    {}
    bool isValid() const;
    DrinkBuilder& setName(const std::string& name);
    DrinkBuilder& setSugar(int sugar);
    DrinkBuilder& setTemperature(int temperature);
    DrinkBuilder& setWithMilk(bool withMilk);
    void print() const;
};

#endif 