#ifndef GAME_HPP
#define GAME_HPP

#include "action.hpp"
#include <cstring>

class Game
{
private:
    Player* player;
    Board* board;

    bool won() const;
    bool lost() const;

public:
    Game(Player* player, Board* board);

    void run();
};

#endif
