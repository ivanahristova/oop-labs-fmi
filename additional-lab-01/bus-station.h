#ifndef BUS_STATION_H
#define BUS_STATION_H

#include "bus.h"

class BusStation
{
private:
    Bus** buses;
    int capacity;
    int count;

    void copy_from(const BusStation& other);
    void free_memory();

    void resize();
    bool exists(const Bus& bus);

public:
    BusStation();
    BusStation(const BusStation& other);
    BusStation& operator=(const BusStation& other);
    ~BusStation();
    BusStation& operator=(BusStation&& other) noexcept;
    BusStation(BusStation&& other) noexcept;

    bool sit_passenger();
    void add_bus_for_stay(Bus& bus);

    friend std::ostream& operator<<(std::ostream& os, const BusStation& bus_station);

};

#endif
