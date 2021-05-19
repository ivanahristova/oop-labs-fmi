#include "car.hpp"
#include <cmath>
#include "insufficient-fuel-error.hpp"

Car::Car(Engine* engine, Battery* battery, Tyre* tyres[4], int weight, double fuel_tank_volume)
    : engine(engine), battery(battery), km_driven(0), fuel_tank(fuel_tank_volume)
{
    for (int i = 0; i < 4; i++)
    {
        this->tyres[i] = tyres[i];
    }

    set_weight(weight);
}

void Car::set_weight(int weight)
{
    if (weight < 0)
    {
        throw std::invalid_argument("Trying to set invalid car weight");
    }

    this->weight = weight;
}

double Car::fuel_per_km() const
{
    const double base_horsepower = 3.6;
    const double base_weight = 8;

    const double from_hp = log(engine->get_horsepower()) / log(base_horsepower);
    const double from_weight = + log(weight) / log(base_weight);

    return (from_hp + from_weight) / 100.0;
}

void Car::drive(double km)
{
    if (km < 0)
    {
        throw std::invalid_argument("Trying to drive car for negative distance");
    }

    try
    {
        fuel_tank.use(fuel_per_km() * km);
    }
    catch (const insufficient_fuel_error& e)
    {
        return;
    }

    km_driven += km;
}

double Car::power_weight_ratio() const
{
    return 1.0 * engine->get_horsepower() / weight;
}

Car* drag_race(Car* car1, Car* car2)
{
    const double race_distance = 0.4;

    try
    {
        car1->drive(race_distance);
    }
    catch (const insufficient_fuel_error& e)
    {
        try
        {
            car2->drive(race_distance);
        }
        catch(const insufficient_fuel_error& e)
        {
            return nullptr;
        }

        return car2;
    }

    try
    {
        car2->drive(race_distance);
    }
    catch (const insufficient_fuel_error& e)
    {
        return car1;
    }

    Car* winner = car1->power_weight_ratio() > car2->power_weight_ratio() ? car1 : car2;

    return winner;
}

const FuelTank& Car::get_fuel_tank() const
{
    return fuel_tank;
}
