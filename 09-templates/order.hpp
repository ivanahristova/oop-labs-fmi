#ifndef ORDER_HPP
#define ORDER_HPP

#include "meal.hpp"

class Order
{
private:
    static const int address_max_len = 256;
    static int next_id;

    Meal meal;
    unsigned int id;
    unsigned int grams;
    char address[address_max_len];

public:
    Order();
    Order(Meal meal, int grams, const char* address);
    Meal get_meal() const;
    const char* get_name_of_meal() const;
    unsigned int get_grams() const;
    const char* get_address() const;
};

#endif // ORDER_HPP
