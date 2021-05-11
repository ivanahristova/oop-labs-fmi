#ifndef BATTERY_HPP
#define BATTERY_HPP

#include "car-part.hpp"

class Battery : public CarPart
{
private:
    int amp_hours;
    char* battery_id;

    void copy_from(const Battery& other);
    void free_memory();

    void set_amp_hours(int amp_hours);
    void set_battery_id(const char* battery_id);

public:
    Battery(const char* id, const char* manufacturer, const char* description,
            const char* battery_id, int amp_hours);

    Battery(const Battery& other);
    const Battery& operator=(const Battery& other);
    ~Battery();
};

#endif // BATTERY_HPP
