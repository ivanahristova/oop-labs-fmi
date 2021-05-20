#include "warehouse.h"

Warehouse::Warehouse()
    : items_count(0), items_capacity(8)
{
    items = new ItemWithQuantity*[8];
}

// Rule of three

void Warehouse::add_product(ItemWithQuantity* item)
{
    items[items_count] = item;
    items_count++;
}

double Warehouse::get_total_price_of_items() const
{
    double sum = 0;
    for (int i = 0; i < items_count; i++)
    {
        sum += items[i]->get_total_price();
    }
    return sum;
}

void Warehouse::print_statistics() const
{
    for (int i = 0; i < items_count; i++)
    {
        items[i]->print_statistics();
        std::cout << '\n';
    }
}