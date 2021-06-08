#include "coin.h"

int operator*(Coin coin)
{
    switch (coin)
    {
    case Coin::One:
        return 1;

    case Coin::Two:
        return 2;

    case Coin::Five:
        return 5;

    case Coin::Ten:
        return 10;

    case Coin::Twenty:
        return 20;

    case Coin::Fifty:
        return 50;

    case Coin::Lev:
        return 100;

    case Coin::TwoLeva:
        return 200;

    default:
        return -1;
    }
}
