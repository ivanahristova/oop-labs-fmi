#ifndef BOARD_HPP
#define BOARD_HPP

#include "action.hpp"
#include "position.hpp"

class Action;

class Board
{
public:
    static const int board_size = 5;

private:
    Action* matrix[board_size][board_size];

public:
    Board();

    void set_action(Action* action, Position position);
    Action* get_action(Position position) const;

    bool is_valid_position(int row, int col) const;
};

#endif
