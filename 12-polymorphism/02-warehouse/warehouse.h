#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "item-with-quantity.h"

class Warehouse
{
private:
    ItemWithQuantity** items;
    int items_count;
    int items_capacity;

    void copy_from(const Warehouse& other);
    void free_memory();
public:
    Warehouse();
    Warehouse(const Warehouse& other);
    Warehouse& operator=(const Warehouse& other);
    ~Warehouse();

    void add_product(ItemWithQuantity* item);

    double get_total_price_of_items() const;

    void print_statistics() const;
};

#endif
