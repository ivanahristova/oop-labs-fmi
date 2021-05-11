#include "battery.hpp"
#include <stdexcept>
#include <cstring>

Battery::Battery(const char* id, const char* manufacturer, const char* description,
        const char* battery_id, int amp_hours)
    : CarPart(id, manufacturer, description)
{
    set_amp_hours(amp_hours);
    set_battery_id(battery_id);
}

void Battery::set_amp_hours(int amp_hours)
{
    if (amp_hours < 0)
    {
        throw std::invalid_argument("Trying to create car battery with invalid amp hours");
    }
    this->amp_hours = amp_hours;
}

void Battery::set_battery_id(const char* battery_id)
{
    if (battery_id == nullptr)
    {
        throw std::invalid_argument("Trying to create car with null battery id");
    }

    this->battery_id = new char[strlen(battery_id) + 1];
    strcpy(this->battery_id, battery_id);
}

void Battery::copy_from(const Battery& other)
{
    set_amp_hours(other.amp_hours);
    set_battery_id(other.battery_id);
}

void Battery::free_memory()
{
    delete[] battery_id;
}

Battery::Battery(const Battery& other)
    : CarPart(other)
{
    copy_from(other);
}

const Battery& Battery::operator=(const Battery& other)
{
    if (this != &other)
    {
        CarPart::operator=(other);

        free_memory();
        copy_from(other);
    }

    return *this;
}

Battery::~Battery()
{
    free_memory();
}
