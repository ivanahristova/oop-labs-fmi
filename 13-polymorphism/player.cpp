#include "player.hpp"

Player::Player()
    : position(), is_alive(1) {}

void Player::set_status(bool is_alive)
{
    this->is_alive = is_alive;
}

bool Player::get_status() const
{
    return is_alive;
}

void Player::set_position(Board* board, int row, int col)
{
    if (!board->is_valid_position(row, col))
    {
        throw std::out_of_range("Trying to set invalid player position");
    }

    position.row = row;
    position.col = col;
}

Position Player::get_position() const
{
    return position;
}

void Player::move_helper(Board* board, int row_change, int col_change, int steps)
{
    set_position(board, position.row + row_change * steps, position.col + col_change * steps);
}

void Player::move(Board* board, Direction direction, int steps)
{
    switch (direction)
    {
    case Direction::Up: 
        move_helper(board, -1, 0, steps);
        break;
    
    case Direction::Down: 
        move_helper(board, 1, 0, steps);
        break;

    case Direction::Left: 
        move_helper(board, 0, -1, steps);
        break;

    case Direction::Right: 
        move_helper(board, 0, 1, steps);
        break;

    default:
        break;
    }
}
