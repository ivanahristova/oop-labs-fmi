#include <iostream>
#include "sneaker-shop.hpp"
#include "sneakers.hpp"
#include "helpers.hpp"
#include "exceptions/existing_sneakers_error.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_TREAT_CHAR_STAR_AS_STRING
#include "../../lib/doctest/doctest/doctest.h"

TEST_CASE("Sneaker shop")
{
    SneakerShop shop;
    Sneakers sneakers_default("Default", "Default", 100, 30, 0);
    Sneakers sneakers_unavailable("Unavailable", "Unavailable", 100, 0, 0);

    std::stringstream ss_input;
    std::stringstream ss_output;

    const int default_rating = 5;

    char buffer1[1500];
    char buffer2[1500];

    SUBCASE("Add sneakers")
    {
        SUBCASE("Throws if sneakers with same name already exist")
        {
            ss_input << sneakers_default << "\n";

            CHECK_THROWS_AS(shop.add_sneakers(ss_input, ss_output, sneakers_default),
                            existing_sneakers_error);

        }

        SUBCASE("Successfully appends sneakers")
        {
            std::stringstream ss_expected;

            ss_expected << sneakers_default << "\n";
            shop.add_sneakers(ss_input, ss_output, sneakers_default);

            get_last_line(ss_expected, buffer1);
            get_last_line(ss_output, buffer2);

            CHECK_EQ(buffer1, buffer2);
        }
    }

    SUBCASE("Buy pair of sneakers")
    {
        SUBCASE("Buying sneakers with 0 quantity does not change quantity")
        {
            ss_input << sneakers_unavailable << "\n";

            shop.buy_pair_from_model(ss_input, ss_output, sneakers_unavailable.get_model());

            CHECK_EQ(ss_output.str(), ss_input.str());
        }

        SUBCASE("Buying sneakers with positive quantity reduces quantity")
        {
            ss_input << sneakers_default << "\n";

            Sneakers sneakers_before = shop.get_sneakers_by_model(ss_input, sneakers_default.get_model());

            shop.buy_pair_from_model(ss_input, ss_output, sneakers_default.get_model());

            Sneakers sneakers_after = shop.get_sneakers_by_model(ss_output, sneakers_default.get_model());

            CHECK_EQ(sneakers_before.get_available() - 1, sneakers_after.get_available());
        }
    }

    SUBCASE("Add pair of sneakers")
    {
        SUBCASE("Adding sneakers increases quantity")
        {
            ss_input << sneakers_default << "\n";

            Sneakers sneakers_before = shop.get_sneakers_by_model(ss_input, sneakers_default.get_model());

            shop.add_pair_from_model(ss_input, ss_output, sneakers_default.get_model());

            Sneakers sneakers_after = shop.get_sneakers_by_model(ss_output, sneakers_default.get_model());

            CHECK_EQ(sneakers_before.get_available() + 1, sneakers_after.get_available());
        }
    }

    SUBCASE("Add rating for sneakers")
    {
        SUBCASE("Throws for invalid rating")
        {
            ss_input << sneakers_default << "\n";

            const int invalid_rating_under_min = 0;
            const int invalid_rating_over_max = 11;

            CHECK_THROWS_AS(shop.add_rating_for_model(ss_input, ss_output, sneakers_default.get_model(),
                        invalid_rating_under_min),
                        std::invalid_argument);

            CHECK_THROWS_AS(shop.add_rating_for_model(ss_input, ss_output, sneakers_default.get_model(),
                        invalid_rating_over_max),
                        std::invalid_argument);
        }

        SUBCASE("Increases cumulative rating and increments ratings count properly")
        {
            ss_input << sneakers_default << "\n";

            Sneakers sneakers_before = shop.get_sneakers_by_model(ss_input, sneakers_default.get_model());

            shop.add_rating_for_model(ss_input, ss_output, sneakers_default.get_model(), default_rating);

            Sneakers sneakers_after = shop.get_sneakers_by_model(ss_output, sneakers_default.get_model());

            CHECK_EQ(sneakers_before.get_cumulative_rating() + default_rating,
                    sneakers_after.get_cumulative_rating());

            CHECK_EQ(sneakers_before.get_ratings_given() + 1,
                    sneakers_after.get_ratings_given());
        }
    }

    SUBCASE("Remove sneakers")
    {
        SUBCASE("Nothing changes when deleting nonexistent sneaker model")
        {
            ss_input << sneakers_default << "\n";

            shop.remove_model(ss_input, ss_output, sneakers_unavailable.get_model());

            CHECK_EQ(ss_input.str(), ss_output.str());
        }

        SUBCASE("Existing sneaker is removed successfully")
        {
            ss_input << sneakers_default << "\n";

            Sneakers found_sneakers = shop.get_sneakers_by_model(ss_input, sneakers_default.get_model());

            shop.remove_model(ss_input, ss_output, sneakers_default.get_model());

            CHECK_THROWS_WITH_AS(shop.get_sneakers_by_model(ss_output, sneakers_default.get_model()),
                                "Trying to get nonexisting sneakers",
                                std::logic_error);
        }
    }

    SUBCASE("Sort sneakers")
    {
        Sneakers sneakers1("Sneakers1", "Manufacturer1", 100, 30, 0, 24, 5);
        Sneakers sneakers2("Sneakers2", "Manufacturer1", 100, 30, 0, 22, 5);
        Sneakers sneakers3("Sneakers3", "Manufacturer1", 100, 30, 0, 50, 5);
        Sneakers sneakers4("Sneakers4", "Manufacturer1", 100, 30, 0, 30, 10);

        ss_input << sneakers1 << "\n"
                << sneakers2 << "\n"
                << sneakers3 << "\n"
                << sneakers4 << "\n";

        SUBCASE("Sneakers are sorted accordingly")
        {
            shop.sort_models(ss_input, ss_output, false);

            Sneakers curr_sneakers = shop.get_sneakers_at_index(ss_input, 0);
            CHECK(curr_sneakers == sneakers3);

            curr_sneakers = shop.get_sneakers_at_index(ss_input, 1);
            CHECK(curr_sneakers == sneakers1);

            curr_sneakers = shop.get_sneakers_at_index(ss_input, 2);
            CHECK(curr_sneakers == sneakers2);

            curr_sneakers = shop.get_sneakers_at_index(ss_input, 3);
            CHECK(curr_sneakers == sneakers4);

            CHECK_THROWS_AS(shop.get_sneakers_at_index(ss_input, 4), std::out_of_range);
        }
    }
}
