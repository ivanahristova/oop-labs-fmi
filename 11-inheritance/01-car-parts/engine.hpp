#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "car-part.hpp"

class Engine : public CarPart
{
private:
    int horsepower;

public:
    Engine(const char* id, const char* manufacturer, const char* description,
            int horsepower);

    int get_horsepower();

private:
    void set_horsepower(int horsepower);
};


#endif // ENGINE_HPP
