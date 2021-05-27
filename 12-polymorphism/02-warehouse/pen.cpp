#include "pen.h"

Pen::Pen(const char* name, double price, int quantity, int ink_quantity)
    : ItemWithQuantity(name, price, quantity), ink_quantity(ink_quantity)
{
    const char* default_last_written_text = "I'm a new pen!";
    last_written_text = new char[strlen(default_last_written_text) + 1];
}

double Pen::get_item_price() const
{
    return ink_quantity * price;
}

void Pen::set_last_written_text(const char* word)
{
    delete[] last_written_text;

    last_written_text = new char[strlen(word) + 1];
    strcpy(last_written_text, word);
}

void Pen::copy_from(const Pen& other)
{
    ink_quantity = other.ink_quantity;

    last_written_text = new char[strlen(other.last_written_text) + 1];
    strcpy(last_written_text, other.last_written_text);
}

void Pen::free_memory()
{
    delete[] last_written_text;
}

Pen::Pen(const Pen& other)
    : ItemWithQuantity(other)
{
    copy_from(other);
}

Pen& Pen::operator=(const Pen& other)
{
    if (this != &other)
    {
        ItemWithQuantity::operator=(other);

        free_memory();
        copy_from(other);
    }

    return *this;
}

Pen::~Pen()
{
    free_memory();
}
