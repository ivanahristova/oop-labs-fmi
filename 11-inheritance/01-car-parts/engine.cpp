#include "engine.hpp"
#include "car-part.hpp"
#include <stdexcept>

Engine::Engine(const char* id, const char* manufacturer, const char* description, int horsepower)
    : CarPart(id, manufacturer, description)
{
    set_horsepower(horsepower);
}

int Engine::get_horsepower() const
{
    return horsepower;
}

std::ostream& operator<<(std::ostream& o_stream, const Engine& engine)
{
    o_stream << (const CarPart&)engine;
    return o_stream << " – " << engine.get_horsepower() << " hp";
}

void Engine::set_horsepower(int horsepower)
{
    if (horsepower < 0)
    {
        throw std::invalid_argument("Trying to create engine with invalid horsepower");
    }
    this->horsepower = horsepower;
}
