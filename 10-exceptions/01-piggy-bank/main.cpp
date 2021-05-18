#include "piggy-bank.h"

int main()
{
    PiggyBank b;
    const int coins_count = 7;
    Coin coins_b[coins_count] = {Coin::One, Coin::One, Coin::One, Coin::Twenty, Coin::Twenty, Coin::Twenty, Coin::Lev};
    b.add_coins(coins_b, coins_count);
    std::cout << b.get_sum() << '\n';

    Coin coins_c[coins_count] = {Coin::One, Coin::One, Coin::One, Coin::Twenty, Coin::Twenty, Coin::Twenty, Coin::Lev};
    PiggyBank c;
    c.break_piggy_bank();
    c.add_coins(coins_c, coins_count);
    std::cout << c.get_sum() << '\n';

    return 0;
}