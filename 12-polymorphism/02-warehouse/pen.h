#ifndef PEN_H
#define PEN_H

#include "item-with-quantity.h"

class Pen : public ItemWithQuantity
{
    int ink_quantity; // in ml
    char* last_written_text;

    void copy_from(const Pen& other);
    void free_memory();

public:
    Pen(const char* name, double price, int quantity, int ink_quantity);
    Pen(const Pen& other);
    Pen& operator=(const Pen& other);
    ~Pen();

    void set_last_written_text(const char* word);

    double get_item_price() const override;
};

#endif
