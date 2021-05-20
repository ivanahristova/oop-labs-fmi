#ifndef PEN_H
#define PEN_H

#include "item-with-quantity.h"

class Pen : public ItemWithQuantity
{
    int ink_quantity; // in ml

public:
    Pen(const char* name, double price, int quantity, int ink_quantity);

    double get_item_price() const override;
};

#endif