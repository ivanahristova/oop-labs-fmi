#ifndef INSUFFICIENT_FUEL_ERROR_HPP
#define INSUFFICIENT_FUEL_ERROR_HPP

#include <stdexcept>
#include "car.hpp"

class insufficient_fuel_error : public std::logic_error
{
public:
    insufficient_fuel_error(const char* msg);
};

#endif // INSUFFICIENT_FUEL_ERROR_HPP
