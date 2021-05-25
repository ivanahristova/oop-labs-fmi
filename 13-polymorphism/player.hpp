#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "position.hpp"
#include "board.hpp"
#include "direction.hpp"

class Board;

class Player
{
private:
    Position position;
    bool is_alive;

    void move_helper(Board* board, int row, int col, int steps = 1);

public:
    Player();
    
    void set_status(bool is_alive);
    bool get_status() const;
    
    void set_position(Board* board, int row, int col);
    Position get_position() const;

    void move(Board* board, Direction direction, int steps = 1);

};

#endif
