#ifndef CAR_HPP
#define CAR_HPP

#include "engine.hpp"
#include "battery.hpp"
#include "tyre.hpp"
#include "fuel-tank.hpp"

class Car
{
private:
    FuelTank fuel_tank;
    Engine* engine;
    Battery* battery;
    Tyre* tyres[4];
    double km_driven;
    int weight;

    void set_weight(int weight);

public:
    Car(Engine* engine, Battery* battery, Tyre* tyres[4], int weight, double fuel_tank_volume);
    void drive(double km);
    const FuelTank& get_fuel_tank() const;

    double fuel_per_km() const;
    double power_weight_ratio() const;
};

Car* drag_race(Car* car1, Car* car2);

#endif // CAR_HPP
