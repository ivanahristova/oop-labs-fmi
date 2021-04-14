#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <cstring>

class Bus
{
private:
    char* license_plate;
    int capacity;
    int passengers;

    // helper functions for big-3
    void copy_from(const Bus& other);
    void free_memory();

public:
    // constructors
    Bus();
    Bus(const char* license_plate, int capacity, int passengers);

    // big-5
    Bus(const Bus& other);
    Bus& operator=(const Bus& other);
    ~Bus();
    Bus& operator=(Bus&& other) noexcept;
    Bus(Bus&& other) noexcept;

    // getters
    int get_passengers() const;
    int get_capacity() const;
    const char* get_license_plate() const;

    // functionality
    bool sit_passenger();
    bool full();

    // operators
    bool operator==(const Bus& other);
    friend std::ostream& operator<<(std::ostream& os, const Bus& bus);

};

#endif
