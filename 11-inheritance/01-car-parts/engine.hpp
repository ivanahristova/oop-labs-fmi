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

    int get_horsepower() const;

private:
    void set_horsepower(int horsepower);
};

std::ostream& operator<<(std::ostream& o_stream, const Engine& engine);

#endif // ENGINE_HPP
