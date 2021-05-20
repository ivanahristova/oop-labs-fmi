#include "pen.h"

Pen::Pen(const char* name, double price, int quantity, int ink_quantity) 
    : ItemWithQuantity(name, price, quantity), ink_quantity(ink_quantity) {}

double Pen::get_item_price() const 
{
    return ink_quantity * price / 100;
}