#include <iostream>

#include "car.hpp"

int main()
{
    Engine engine1("456", "Honda", "Honda engine", 150);
    Tyre tyre1("123", "Bridgestone", "Summer tyres", 185, 65, 14);
    Battery battery1("789", "Bosch", "Bosch battery", "BAT1", 80);

    std::cout << engine1 << "\n";
    std::cout << tyre1 << "\n";
    std::cout << battery1 << "\n\n";

    Tyre* tyres[4] = {&tyre1, &tyre1, &tyre1, &tyre1};
    Car car1(&engine1, &battery1, tyres, 1500, 60);

    // std::cout << car1.get_fuel_tank().get_available() << "\n";
    car1.drive(300);
    // std::cout << car1.get_fuel_tank().get_available() << "\n";

    Engine engine2("382", "Volkswagen Group", "Engine", 140);
    Car car2(&engine2, &battery1, tyres, 1350, 60);

    Car* winner = drag_race(&car1, &car2);

    // std::cout << car1.power_weight_ratio() << "\n";
    // std::cout << car2.power_weight_ratio() << "\n";

    if (winner != nullptr)
    {
        std::cout << winner->power_weight_ratio() << "\n";
    }
}
