#include "order.hpp"
#include <cassert>
#include <cstring>

int Order::next_id = 0;

Order::Order()
    : meal(Meal::Shopska), grams(0), id(next_id++)
{
    strcpy(address, "Unknown address");
}

Order::Order(Meal meal, int grams, const char* address)
    : meal(meal), id(next_id++)
{
    assert(grams > 0);
    this->grams = grams;

    const int len_address = strlen(address);
    int len_to_copy = len_address < address_max_len ? (len_address + 1) : (address_max_len - 1);

    strncpy(this->address, address, len_to_copy);
}

Meal Order::get_meal() const
{
    return meal;
}

unsigned int Order::get_grams() const
{
    return grams;
}

const char* Order::get_address() const
{
    return address;
}

const char* Order::get_name_of_meal() const
{
    switch (meal)
    {
        case Meal::Shopska:
            return "Shopska salad";
        case Meal::Rice:
            return "Rice with vegetables";
        case Meal::Chicken:
            return "Chicken";
        default:
            return "Unknown meal";
    }
}
