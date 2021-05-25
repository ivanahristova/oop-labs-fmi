#include "board.hpp"

Board::Board()
{
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            matrix[i][j] = nullptr;
        }
    }
}

void Board::set_action(Action* action, Position position)
{
    if (!is_valid_position(position.row, position.col))
    {
        throw std::out_of_range("Invalid field place.");
    }

    matrix[position.row][position.col] = action;
}

Action* Board::get_action(Position position) const
{
    if (!is_valid_position(position.row, position.col))
    {
        throw std::out_of_range("Invalid field place.");
    }

    return matrix[position.row][position.col];
}

bool Board::is_valid_position(int row, int col) const
{
    return row >= 0 && row < board_size 
        && col >= 0 && col <= board_size;
}
