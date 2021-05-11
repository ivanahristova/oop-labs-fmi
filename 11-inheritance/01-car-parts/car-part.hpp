#ifndef CarPart_HPP
#define CarPart_HPP
#include <iostream>

class CarPart
{
private:
    char* id;
    char* manufacturer;
    char* description;
public:
    CarPart(const char* id, const char* manufacturer, const char* description);

    CarPart(const CarPart& other);
    const CarPart& operator=(const CarPart& other);
    ~CarPart();

    void set_description(const char* description);
    void set_manufacturer(const char* manufacturer);

private:
    void set_id(const char* id);
    void copy_from(const CarPart& other);
    void free_memory();
};

#endif // CarPart_HPP
