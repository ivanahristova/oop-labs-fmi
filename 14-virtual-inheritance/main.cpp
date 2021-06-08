
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_TREAT_CHAR_STAR_AS_STRING
#include "../lib/doctest/doctest/doctest.h"

#include "artist.hpp"
#include "writer.hpp"

TEST_CASE("Testing Artist")
{
    Artist default_artist("default");

    SUBCASE("Default constructor sets up an empty artist")
    {
        CHECK_EQ(default_artist.get_followers(), 0);
        CHECK(default_artist.get_released_works() == 0);
    }

    SUBCASE("Gaining a follower increases followers count")
    {
        int followers_before = default_artist.get_followers();

        default_artist.gain_follower();

        int followers_after = default_artist.get_followers();

        CHECK_EQ(followers_before + 1, followers_after);
    }

    SUBCASE("Artist creates work with proper title")
    {
        const char* work_title = "work1";

        Work retrieved_work = default_artist.produce_work(work_title);

        CHECK_EQ(work_title, retrieved_work.get_title());
    }
}

TEST_CASE("Testing Writer")
{
    Writer default_writer("default");
    const char* default_work_name = "work1";

    SUBCASE("")
    {
        CHECK_EQ(default_writer.average_length(), 0);

        default_writer.produce_written_work(default_work_name, 3);
        default_writer.produce_written_work(default_work_name, 5);
        default_writer.produce_written_work(default_work_name, 4);

        CHECK_EQ(default_writer.average_length(), 4);
    }

}
