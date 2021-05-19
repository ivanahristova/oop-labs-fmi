#ifndef FUEL_TANK_HPP
#define FUEL_TANK_HPP

class FuelTank
{
private:
    double capacity;
    double available;

    void set_capacity(double capacity);

public:
    FuelTank(double capacity);
    void fill(double to_fill_with);
    void use(double to_use);

    double get_capacity() const;
    double get_available() const;
};

#endif // FUEL_TANK_HPP
