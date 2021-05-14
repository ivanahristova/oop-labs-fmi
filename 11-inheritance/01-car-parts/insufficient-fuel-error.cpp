#include "insufficient-fuel-error.hpp"

insufficient_fuel_error::insufficient_fuel_error(const char* msg)
    : std::logic_error(msg)
{}
