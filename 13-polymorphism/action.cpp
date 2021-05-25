#include "action.hpp"

EmptyAction::EmptyAction() 
{}

void EmptyAction::execute()
{
    // do nothing
}

const char* EmptyAction::get_description() const
{
    return "Empty";
}


LightSurroundings::LightSurroundings(Board* board, Position position)
    : board(board), position(position) {}

void LightSurroundings::execute()
{
    const char* end_of_board = "Wall";

    std::cout << "Left: ";
    if (position.col > 0)
    {
        std::cout << board->get_action(Position(position.row, position.col - 1))->get_description() 
                << "\n";
    }
    else
    {
        std::cout << end_of_board << '\n';
    }

    std::cout << "Right: ";
    if (position.col < board->board_size - 1)
    {
        std::cout << board->get_action(Position(position.row, position.col + 1))->get_description()
                << '\n';
    }
    else
    {
        std::cout << "End of field.\n";
    }
    
    std::cout << "Up: ";
    if (position.row > 0)
    {
        std::cout << board->get_action(Position(position.row - 1, position.col))->get_description()
                << '\n';
    }
    else
    {
        std::cout << end_of_board << '\n';
    }

    std::cout << "Down: ";
    if (position.row < board->board_size - 1)
    {
        std::cout << board->get_action(Position(position.row + 1, position.col))->get_description()
                << '\n';
    }
    else
    {
        std::cout << end_of_board << '\n';
    }
}

const char* LightSurroundings::get_description() const
{
    return "Firefly";
}


KillPlayer::KillPlayer(Player* player)
    : player(player) {}

void KillPlayer::execute()
{
    player->set_status(false);
}

const char* KillPlayer::get_description() const
{
    return "Spider";
}


TeleportPlayer::TeleportPlayer(Player* player, Board* board)
    : player(player), board(board) {}

void TeleportPlayer::execute()
{
    player->set_position(board, 0, 0);
}

const char* TeleportPlayer::get_description() const
{
    return "Portal";
}


MovePlayer::MovePlayer(Board* board, Direction direction, Player* player)
    : board(board), direction(direction), player(player) {}

void MovePlayer::execute()
{
    player->move(board, direction, 1);
}

const char* MovePlayer::get_description() const
{
    return "Moves player";
}
