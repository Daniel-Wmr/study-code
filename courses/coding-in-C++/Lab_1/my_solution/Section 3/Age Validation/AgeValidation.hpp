#ifndef AGEVALIDATION_HPP
#define AGEVALIDATION_HPP

#include <cstdint>

namespace validation
{
    bool isAdult(uint8_t age);
    bool isSenior(uint8_t age);
};

typedef enum State
{
    CHILD,
    ADULT,
    SENIOR
} State;

#endif