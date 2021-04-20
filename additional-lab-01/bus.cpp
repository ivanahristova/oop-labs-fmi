#include "bus.h"

void Bus::copy_from(const Bus& other)
{
    this->capacity = other.capacity;
    this->passengers = other.passengers;

    // allocating memory for the license plate
    int length = strlen(other.license_plate);
    this->license_plate = new char[length + 1];

    // copying the license plate content (not only the pointer)
    strcpy(this->license_plate, other.license_plate);
}

void Bus::free_memory()
{
    delete[] license_plate;
}

Bus::Bus()
    : license_plate(nullptr), capacity(0), passengers(0) {}

Bus::Bus(const char* license_plate, int capacity, int passengers)
    : capacity(capacity), passengers(passengers)
{
    this->license_plate = new char[strlen(license_plate) + 1];
    strcpy(this->license_plate, license_plate);
}

Bus::Bus(const Bus& other)
{
    copy_from(other);
}

Bus& Bus::operator=(const Bus& other)
{
    if (this != &other)
    {
        free_memory();
        copy_from(other);
    }
    return *this;
}

Bus::~Bus()
{
    free_memory();
}

Bus& Bus::operator=(Bus&& other) noexcept
{
    free_memory();

    this->license_plate = std::move(other.license_plate);
    this->capacity = std::move(other.capacity);
    this->passengers = std::move(other.passengers);

    other.license_plate = nullptr;
    other.capacity = 0;
    other.passengers = 0;

    return *this;
}

Bus::Bus(Bus&& other) noexcept
    : license_plate(std::move(other.license_plate))
    , capacity(std::move(other.capacity))
    , passengers(std::move(other.passengers))
{
    other.license_plate = nullptr;
    other.capacity = 0;
    other.passengers = 0;
}

int Bus::get_passengers() const
{
    return passengers;
}

int Bus::get_capacity() const
{
    return capacity;
}

const char* Bus::get_license_plate() const
{
    return license_plate;
}

bool Bus::sit_passenger()
{
    if (passengers == capacity)
    {
        return false;
    }

    passengers++;
    return true;
}

bool Bus::full()
{
    return passengers == capacity;
}

bool Bus::operator==(const Bus& other)
{
    return strcmp(license_plate, other.license_plate) == 0;
}

std::ostream& operator<<(std::ostream& os, const Bus& bus)
{
    os << bus.get_license_plate() << ' '
       << bus.get_capacity() << ' '
       << bus.get_passengers() << '\n';

    return os;
}
