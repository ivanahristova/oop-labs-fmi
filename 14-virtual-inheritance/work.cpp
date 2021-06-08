#include <stdexcept>
#include <cstring>
#include "work.hpp"

Work::Work(const char* title)
{
    const int title_len = strlen(title);
    strncpy(this->title, title, 100);
    const int terminator_index = title_len < 199 ? title_len : 199;
    this->title[terminator_index] = '\0';

    cumulative_rating = 0;
    ratings_given = 0;
}

const char* Work::get_title()
{
    return title;
}

double Work::get_average_rating()
{
    if (ratings_given < 1)
    {
        return 0.0;
    }

    return 1.0 * cumulative_rating / ratings_given;
}

void Work::add_rating(int rating)
{
    if (rating < min_rating || rating > max_rating)
    {
        throw std::invalid_argument("Trying to add invalid rating");
    }

    cumulative_rating += rating;
    ratings_given++;
}
