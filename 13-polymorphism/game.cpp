#include "game.hpp"

Game::Game(Player* player, Board* board) 
    : player(player), board(board) {}

bool Game::won() const
{
    return player->get_position().col >= board->board_size;
}

bool Game::lost() const
{
    return !player->get_status();
}

void Game::run()
{
    char input[4];
    do 
    {
        std::cout << "Current position: (" << player->get_position().row << ", " << player->get_position().col << ") - ";

        if (won())
        {
            std::cout << "You won!\n";
            break;
        }

        Action* current_action = board->get_action(player->get_position());
        std::cout << current_action->get_description() << '\n';
        current_action->execute();

        if (lost())
        {
            std::cout << "You died!\n";
            break;
        }

        std::cin >> input;
        std::cout << '\n';

        if (strcmp(input, "end") == 0)
        {
            break;
        }

        Direction direction;
        try
        {
            direction = get_direction_by_char(input[0]);
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }

        Action* move_action = new MovePlayer(board, direction, player);
        try
        {
            move_action->execute();
        }
        catch(const std::out_of_range& e)
        {
            std::cerr << "Cannot move - wall" << '\n';
        }
        
        delete move_action;    

    } while (strcmp(input, "end") != 0);
}
