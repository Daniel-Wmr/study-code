#ifndef AGEVALIDATION_HPP
#define AGEVALIDATION_HPP

#include <cstdint>

namespace validation
{
    /**
     * @brief Checks whether it is a senior or not.
     * 
     * Checks whether the entered age is greater than a certain value.
     * 
     * @param[in] age is the entered number (-> age)
     * @return true/false (boolean)
     */
    bool isAdult(uint8_t age);

    /**
     * @brief Checks whether it is an adult or not.
     * 
     * Checks whether the entered age is greater than a certain value.
     * 
     * @param[in] age is the entered number (-> age)
     * @return true/false (boolean)
     */
    bool isSenior(uint8_t age);
};

typedef enum State
{
    CHILD,
    ADULT,
    SENIOR
} State;

#endif