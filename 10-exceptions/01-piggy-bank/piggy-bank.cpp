#include "piggy-bank.h"

PiggyBank::PiggyBank() 
    : count(0), intact(true) {}

PiggyBank::PiggyBank(Coin coins[], int count) 
{
    try 
    {
        add_coins(coins, count);
    }
    catch (std::out_of_range &exception)
    {
        std::cout << exception.what() << '\n';
    }
}

void PiggyBank::add_coins(Coin add_coins[], int add_count)
{
    if (!intact)
    {
        throw std::logic_error("The piggy bank is broken.");
    }

    if (add_count < 0)
    {
        throw std::invalid_argument("The count of coins is a negative number.");
    }

    if (count + add_count > max_coins_count)
    {
        throw std::out_of_range("There are more coins than can fit in the piggy bank.");
    }

    for (int i = 0; i < add_count; i++)
    {
        coins[count] = add_coins[i];
        count++;
    }
}

int PiggyBank::get_sum() 
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += *coins[i];   
    }

    return sum;
}

int PiggyBank::break_piggy_bank() 
{
    intact = false;
    return get_sum();
}