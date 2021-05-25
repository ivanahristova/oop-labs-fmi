#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include <stdexcept>

enum class Direction { Up, Down, Left, Right };
Direction get_direction_by_char(char ch);

#endif
