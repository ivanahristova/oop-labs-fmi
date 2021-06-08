#ifndef PIGGY_BANK_HPP
#define PIGGY_BANK_HPP

#include <iostream>
#include <stdexcept>
#include "coin.h"

class PiggyBank
{
public:
    static const int max_coins_count = 300;
private:
    Coin coins[max_coins_count];
    int count;
    bool intact;

public:
    PiggyBank();
    PiggyBank(Coin coins[], int count);

    void add_coins(Coin coins[], int count);
    int get_sum();
    int break_piggy_bank();
};

#endif
