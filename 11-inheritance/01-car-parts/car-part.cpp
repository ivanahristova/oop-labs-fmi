#include "car-part.hpp"
#include <stdexcept>
#include <cstring>

CarPart::CarPart(const char* id, const char* manufacturer, const char* description)
{
    set_id(id);
    set_manufacturer(manufacturer);
    set_description(description);
}

void CarPart::copy_from(const CarPart& other)
{
    set_id(other.id);
    set_manufacturer(other.manufacturer);
    set_description(other.description);
}

void CarPart::free_memory()
{
    delete[] id;
    delete[] manufacturer;
    delete[] description;
}

CarPart::CarPart(const CarPart& other)
{
    copy_from(other);
}

const CarPart& CarPart::operator=(const CarPart& other)
{
    if (this != &other)
    {
        free_memory();
        copy_from(other);
    }
    return *this;
}

CarPart::~CarPart()
{
    free_memory();
}

void CarPart::set_id(const char* id)
{
    if (id == nullptr)
    {
        throw std::invalid_argument("Trying to set null CarPart id");
    }

    this->id = new char[strlen(id) + 1];
    strcpy(this->id, id);
}

void CarPart::set_description(const char* description)
{
    if (description == nullptr)
    {
        throw std::invalid_argument("Trying to set null CarPart description");
    }

    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

void CarPart::set_manufacturer(const char* manufacturer)
{
    if (manufacturer == nullptr)
    {
        throw std::invalid_argument("Trying to set null CarPart manufacturer");
    }

    this->manufacturer = new char[strlen(manufacturer) + 1];
    strcpy(this->manufacturer, manufacturer);
}

std::ostream& operator<<(std::ostream& o_stream, const CarPart& CarPart)
{
    return o_stream << "(" << CarPart.id << ") by "
            << CarPart.manufacturer << " – "
            << CarPart.description;
}
