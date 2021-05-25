#include "direction.hpp"

Direction get_direction_by_char(char ch)
{
    switch (ch)
    {
    case 'l': 
        return Direction::Left;

    case 'r': 
        return Direction::Right;
    
    case 'd': 
        return Direction::Down;

    case 'u': 
        return Direction::Up;

    default: 
        throw std::invalid_argument("Invalid direction.");
    }
}
