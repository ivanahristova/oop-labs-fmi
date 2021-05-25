#include "game.hpp"
#include "action.hpp"

int main()
{
    // Примерно поле:
    // E E T E K
    // T L E T E
    // E K E E E
    // K E E K L
    // T E E L E

    Player p2;
    Board b2;
    Game g2(&p2, &b2);

    Action* act00 = new EmptyAction();
    Action* act01 = new EmptyAction();
    Action* act02 = new TeleportPlayer(&p2, &b2);
    Action* act03 = new EmptyAction();
    Action* act04 = new KillPlayer(&p2);
    Action* act10 = new TeleportPlayer(&p2, &b2);
    Action* act11 = new LightSurroundings(&b2, Position(1, 1));
    Action* act12 = new EmptyAction();
    Action* act13 = new TeleportPlayer(&p2, &b2);
    Action* act14 = new EmptyAction();
    Action* act20 = new EmptyAction();
    Action* act21 = new KillPlayer(&p2);
    Action* act22 = new EmptyAction();
    Action* act23 = new EmptyAction();
    Action* act24 = new EmptyAction();
    Action* act30 = new KillPlayer(&p2);
    Action* act31 = new EmptyAction();
    Action* act32 = new EmptyAction();
    Action* act33 = new KillPlayer(&p2);
    Action* act34 = new LightSurroundings(&b2, Position(3, 4));
    Action* act40 = new TeleportPlayer(&p2, &b2);
    Action* act41 = new EmptyAction();
    Action* act42 = new EmptyAction();
    Action* act43 = new LightSurroundings(&b2, Position(4, 3));
    Action* act44 = new EmptyAction();
    
    b2.set_action(act00, Position(0, 0));
    b2.set_action(act01, Position(0, 1));
    b2.set_action(act02, Position(0, 2));
    b2.set_action(act03, Position(0, 3));
    b2.set_action(act04, Position(0, 4));
    b2.set_action(act10, Position(1, 0));
    b2.set_action(act11, Position(1, 1));
    b2.set_action(act12, Position(1, 2));
    b2.set_action(act13, Position(1, 3));
    b2.set_action(act14, Position(1, 4));
    b2.set_action(act20, Position(2, 0));
    b2.set_action(act21, Position(2, 1));
    b2.set_action(act22, Position(2, 2));
    b2.set_action(act23, Position(2, 3));
    b2.set_action(act24, Position(2, 4));
    b2.set_action(act30, Position(3, 0));
    b2.set_action(act31, Position(3, 1));
    b2.set_action(act32, Position(3, 2));
    b2.set_action(act33, Position(3, 3));
    b2.set_action(act34, Position(3, 4));
    b2.set_action(act40, Position(4, 0));
    b2.set_action(act41, Position(4, 1));
    b2.set_action(act42, Position(4, 2));
    b2.set_action(act43, Position(4, 3));
    b2.set_action(act44, Position(4, 4));

    g2.run();

    delete act00;
    delete act01;
    delete act02;
    delete act03;
    delete act04;
    delete act10;
    delete act11;
    delete act12;
    delete act13;
    delete act14;
    delete act20;
    delete act21;
    delete act22;
    delete act23;
    delete act24;
    delete act30;
    delete act31;
    delete act32;
    delete act33;
    delete act34;
    delete act40;
    delete act41;
    delete act42;
    delete act43;
    delete act44;

    // ---------------------------------------------------------------------------------------
    // Размерът на полето е константен.
    // За да се симулира поле с различен размер, то той трябва да бъде променен в класа Board.

    // Player p;
    // Board b;

    // // E E L
    // // E L T
    // // L K E
    
    // Game g(&p, &b);

    // Action* action00 = new EmptyAction();
    // Action* action01 = new EmptyAction();
    // Action* action02 = new LightSurroundings(&b, Position(0, 2));
    // Action* action10 = new EmptyAction();
    // Action* action11 = new LightSurroundings(&b, Position(1, 1));
    // Action* action12 = new TeleportPlayer(&p, &b);
    // Action* action20 = new LightSurroundings(&b, Position(2, 0));
    // Action* action21 = new KillPlayer(&p);
    // Action* action22 = new EmptyAction();
    // b.set_action(action00, Position(0, 0));
    // b.set_action(action01, Position(0, 1));
    // b.set_action(action02, Position(0, 2));
    // b.set_action(action10, Position(1, 0));
    // b.set_action(action11, Position(1, 1));
    // b.set_action(action12, Position(1, 2));
    // b.set_action(action20, Position(2, 0));
    // b.set_action(action21, Position(2, 1));
    // b.set_action(action22, Position(2, 2));
    
    // g.run();

    // delete action02;
    // delete action01;
    // delete action00;
    // delete action10;
    // delete action11;
    // delete action12;
    // delete action20;
    // delete action21;
    // delete action22;

}
