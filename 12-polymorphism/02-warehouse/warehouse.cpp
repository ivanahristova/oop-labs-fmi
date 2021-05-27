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

void Warehouse::copy_from(const Warehouse& other)
{
    items_count = other.items_count;
    items_capacity = other.items_capacity;

    items = new ItemWithQuantity*[other.items_capacity];
    for (int i = 0; i < other.items_count; i++)
    {
        items[i] = other.items[i];
    }

}

void Warehouse::free_memory()
{
    // delete array of pointers, don't delete items themselves
    delete[] items;
}

Warehouse::Warehouse(const Warehouse& other)
{
    copy_from(other);
}

Warehouse& Warehouse::operator=(const Warehouse& other)
{
    if (this != &other)
    {
        free_memory();
        copy_from(other);
    }

    return *this;
}

Warehouse::~Warehouse()
{
    free_memory();
}
