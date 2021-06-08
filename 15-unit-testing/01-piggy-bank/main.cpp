#include <iostream>
#include "piggy-bank.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_TREAT_CHAR_STAR_AS_STRING
#include "../../lib/doctest/doctest/doctest.h"

TEST_CASE("Piggy bank")
{
    PiggyBank piggy_bank;

    Coin empty_coin_set[] = {};
    Coin default_coin_set[] = {Coin::Ten, Coin::Two, Coin::One};

    const int empty_coin_set_len = 0;
    const int default_coin_set_len = 3;
    const int invalid_coin_set_len = -1;
    const int overflowing_coin_set_len = 301;

    const int default_coin_set_sum = 13;

    SUBCASE("Default piggy bank is empty")
    {
        CHECK_EQ(0, piggy_bank.get_sum());
    }

    SUBCASE("Add coins")
    {
        SUBCASE("Broken piggy bank throws")
        {
            piggy_bank.break_piggy_bank();

            CHECK_THROWS_AS(piggy_bank.add_coins(empty_coin_set, empty_coin_set_len),
                            std::logic_error);
        }

        SUBCASE("Invalid amount to add throws")
        {
            CHECK_THROWS_AS(piggy_bank.add_coins(empty_coin_set, invalid_coin_set_len),
                            std::invalid_argument);
        }

        SUBCASE("Overflowing amount to add throws")
        {
            CHECK_THROWS_WITH_AS(piggy_bank.add_coins(empty_coin_set, overflowing_coin_set_len),
                            "There are more coins than can fit in the piggy bank.",
                            std::out_of_range);
        }

        SUBCASE("Successful coin adding increases sum appropriately")
        {
            const int sum_before = piggy_bank.get_sum();

            piggy_bank.add_coins(default_coin_set, default_coin_set_len);

            const int sum_after = piggy_bank.get_sum();

            CHECK_EQ(sum_before + default_coin_set_sum, sum_after);
        }
    }
}
