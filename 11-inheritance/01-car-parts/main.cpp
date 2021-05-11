#include <iostream>

#include "car.hpp"

int main()
{
    Engine engine1("456", "Honda", "Honda engine", 150);
    Tyre tyre1("123", "Bridgestone", "Summer tyres", 185, 65, 14);
    Battery battery1("789", "Bosch", "Bosch battery", "BAT1", 80);

    std::cout << engine1.get_horsepower() << "\n";
}
