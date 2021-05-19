#include "fuel-tank.hpp"
#include <stdexcept>
#include "insufficient-fuel-error.hpp"

FuelTank::FuelTank(double capacity)
{
    set_capacity(capacity);
    available = capacity;
}

void FuelTank::set_capacity(double capacity)
{
    if (capacity < 0)
    {
        throw std::invalid_argument("Trying to create fuel tank with negative capacity");
    }
}

void FuelTank::fill(double to_fill_with)
{
    if (to_fill_with < 0)
    {
        throw std::invalid_argument("Trying to fill fuel tank with negative amount of fuel");
    }

    if (available + to_fill_with > capacity)
    {
        available = capacity;
    }
    else
    {
        available += to_fill_with;
    }
}

void FuelTank::use(double to_use)
{
    if (to_use < 0)
    {
        throw std::invalid_argument("Trying to use up fuel tank with negative amount of fuel");
    }

    if (to_use > available)
    {
        throw insufficient_fuel_error("Trying to use up fuel tank with more fuel than available");
    }

    available -= to_use;
}

double FuelTank::get_capacity() const
{
    return capacity;
}

double FuelTank::get_available() const
{
    return available;
}
