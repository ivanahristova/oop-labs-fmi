#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "item-with-quantity.h"

class Warehouse
{
    ItemWithQuantity** items;
    int items_count;
    int items_capacity;

public: 
    Warehouse();

    void add_product(ItemWithQuantity* item);

    double get_total_price_of_items() const;

    void print_statistics() const;
};

#endif