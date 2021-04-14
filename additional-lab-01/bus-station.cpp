#include "bus-station.h"

void BusStation::copy_from(const BusStation& other)
{
    this->capacity = other.capacity;
    this->count = other.count;
    this->buses = new Bus*[capacity];

    for (int i = 0; i < capacity; i++)
    {
        if (other.buses[i] != nullptr)
        {
            this->buses[i] = other.buses[i];
            continue;
        }
        this->buses[i] = nullptr;
    }
}

void BusStation::free_memory()
{
    delete[] buses;
}

bool BusStation::exists(const Bus& bus)
{
    for (int i = 0; i < capacity; i++)
    {
        if (buses[i] != nullptr && *buses[i] == bus)
        {
            return true;
        }
    }
    return false;
}


BusStation::BusStation()
    : count(0), capacity(8)
{
    buses = new Bus*[capacity];
    for (int i = 0; i < capacity; i++)
    {
        buses[i] = nullptr;
    }
}

BusStation::BusStation(const BusStation& other)
{
    copy_from(other);
}

BusStation& BusStation::operator=(const BusStation& other)
{
    if (this != &other)
    {
        free_memory();
        copy_from(other);
    }
    return *this;
}

BusStation::~BusStation()
{
    free_memory();
}

BusStation& BusStation::operator=(BusStation&& other) noexcept
{
    free_memory();

    buses = std::move(other.buses);
    capacity = std::move(other.capacity);
    count = std::move(other.count);

    other.buses = nullptr;
    capacity = 0;
    count = 0;
    return *this;
}

BusStation::BusStation(BusStation&& other) noexcept
    : count(std::move(other.count))
    , capacity(std::move(other.capacity))
    , buses(std::move(other.buses))
{
    other.buses = nullptr;
    capacity = 0;
    count = 0;
}

bool BusStation::sit_passenger()
{
    if (count == 0)
    {
        return false; // there are no available buses
    }

    for (int i = 0; i < capacity; i++)
    {
       if (buses[i] != nullptr)
       {
            buses[i]->sit_passenger();
            if (buses[i]->full())
            {
                buses[i] = nullptr;
                count--;
            }
            return true;
       }
    }
    return true;
}

void BusStation::add_bus_for_stay(Bus& bus)
{
    if (count == capacity)
    {
        // resize
    }

    // if the bus is already parked for stay at the bus station
    if (exists(bus))
    {
        return;
    }

    for (int i = 0; i < capacity; i++)
    {
        if (buses[i] == nullptr)
        {
            buses[i] = &bus;
            count++;
            break;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const BusStation& bus_station)
{
    for (int i = 0; i < bus_station.capacity; i++)
    {
        if (bus_station.buses[i] != nullptr)
        {
            os << (*bus_station.buses[i]);
        }
    }
    return os;
}
