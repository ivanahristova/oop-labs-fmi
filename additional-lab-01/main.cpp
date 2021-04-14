#include "bus-station.h"

int main()
{
    BusStation s;

    Bus b1("S 1234 KM", 8, 7);
    Bus b2("S 1234 KM", 8, 5);
    Bus b3("S 1235 KM", 8, 0);

    s.add_bus_for_stay(b1);
    s.add_bus_for_stay(b2);
    s.add_bus_for_stay(b3);

    std::cout << "Initial bus station:\n" << s;

    // The first passenger is added to b1.
    // The capacity is reached => it leaves the station.
    s.sit_passenger();

    // No passengers get added to b2, because already exists

    // All of the rest get added to b3
    s.sit_passenger();
    s.sit_passenger();
    s.sit_passenger();
    s.sit_passenger();
    s.sit_passenger();
    s.sit_passenger();

    std::cout << "After adding passengers:\n" << s;

    return 0;
}
