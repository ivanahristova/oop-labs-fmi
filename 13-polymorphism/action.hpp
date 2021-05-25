#ifndef ACTION_HPP
#define ACTION_HPP

#include <iostream>
#include "player.hpp"
#include "board.hpp"
#include "direction.hpp"

class Board;
class Player;

class Action
{
public:
    virtual void execute() = 0;
    virtual const char* get_description() const = 0;
};

class EmptyAction : public Action
{
public:
    EmptyAction();

    void execute() override;
    const char* get_description() const override;
};

class LightSurroundings : public Action
{
private:
    Board* board;
    Position position;
    
public:
    LightSurroundings(Board* board, Position position);

    void execute() override;
    const char* get_description() const override;

};

class KillPlayer : public Action
{
private:
    Player* player;

public:
    KillPlayer(Player* player);

    void execute() override;
    const char* get_description() const override;
};

class TeleportPlayer : public Action
{
private:
    Player* player;
    Board* board;

public:
    TeleportPlayer(Player* player, Board* board);

    void execute() override;
    const char* get_description() const override;

};

class MovePlayer : public Action
{
private:
    Direction direction;
    Player* player;
    Board* board;

public:
    MovePlayer(Board* board, Direction direction, Player* player);

    void execute() override;
    const char* get_description() const override;
};

#endif
