#include <cstring>
#include "sneakers.hpp"

Sneakers::Sneakers(const char* manufacturer, const char* model, int price,
            int available, int sold, int cumulative_rating, int ratings_given)
{
    strcpy(this->manufacturer, manufacturer);
    strcpy(this->model, model);
    this->available = available;
    this->cumulative_rating = cumulative_rating;
    this->price = price;
    this->sold = sold;
    this->ratings_given = ratings_given;
}

Sneakers::Sneakers()
{
    strcpy(this->manufacturer, "");
    strcpy(this->model, "");
    this->available = 0;
    this->cumulative_rating = 0;
    this->price = 0;
    this->sold = 0;
    this->ratings_given = 0;
}

const char* Sneakers::get_manufacturer() const
{
    return manufacturer;
}

const char* Sneakers::get_model() const
{
    return model;
}

int Sneakers::get_price() const
{
    return price;
}

int Sneakers::get_cumulative_rating() const
{
    return cumulative_rating;
}

int Sneakers::get_ratings_given() const
{
    return ratings_given;
}

int Sneakers::get_available() const
{
    return available;
}

int Sneakers::get_sold() const
{
    return sold;
}

std::ostream& operator<<(std::ostream& o_stream, const Sneakers& sneakers)
{
    const char delimiter = ' ';

    o_stream << sneakers.manufacturer << delimiter
             << sneakers.model << delimiter
             << sneakers.price << delimiter
             << sneakers.cumulative_rating << delimiter
             << sneakers.ratings_given << delimiter
             << sneakers.available << delimiter
             << sneakers.sold;

    return o_stream;
}

std::istream& operator>>(std::istream& i_stream, Sneakers& sneakers)
{
    i_stream >> sneakers.manufacturer
             >> sneakers.model
             >> sneakers.price
             >> sneakers.cumulative_rating
             >> sneakers.ratings_given
             >> sneakers.available
             >> sneakers.sold;

    return i_stream;
}

bool Sneakers::operator==(const Sneakers& other) const
{
    return strcmp(model, other.model) == 0;
}

Sneakers Sneakers::from_text(char* line)
{
    const int token_index_manufacturer = 0;
    const int token_index_model = 1;
    const int token_index_price = 2;
    const int token_index_cumulative_rating = 3;
    const int token_index_ratings_given = 4;
    const int token_index_available = 5;
    const int token_index_sold = 6;

    const int token_count = 7;
    char* tokens[token_count];

    tokenize(line, tokens, token_count);

    Sneakers sneakers;

    strcpy(sneakers.manufacturer, tokens[token_index_manufacturer]);
    strcpy(sneakers.model, tokens[token_index_model]);
    sneakers.price = atoi(tokens[token_index_price]);
    sneakers.cumulative_rating = atoi(tokens[token_index_cumulative_rating]);
    sneakers.ratings_given = atoi(tokens[token_index_ratings_given]);
    sneakers.available = atoi(tokens[token_index_available]);
    sneakers.sold = atoi(tokens[token_index_sold]);

    return sneakers;
}

double Sneakers::get_average_rating() const
{
    if (ratings_given < 1)
    {
        return 0.0;
    }

    return 1.0 * cumulative_rating / ratings_given;
}

void Sneakers::tokenize(char* line, char* tokens[], const int all_tokens_count)
{
    const char* delimiter = " ";
    int curr_token_index = 0;

    char* curr_token = strtok(line, delimiter);
    while (curr_token != nullptr)
    {
        tokens[curr_token_index] = curr_token;

        curr_token = strtok(nullptr, delimiter);
        curr_token_index++;
    }
}

void Sneakers::change_quantity(int quantity_change)
{
    if (quantity_change == 0)
    {
        return;
    }

    if (available + quantity_change < 0)
    {
        throw std::out_of_range("Cannot change quantity for sneakers – new quantity is negative");
    }

    available += quantity_change;
}

void Sneakers::add_pair()
{
    change_quantity(1);
}

void Sneakers::remove_pair()
{
    change_quantity(-1);
}

bool Sneakers::is_valid_rating(int rating)
{
    const int min_rating = 1;
    const int max_rating = 10;
    return (rating >= min_rating && rating <= max_rating);
}

void Sneakers::add_rating(int rating)
{
    if (!is_valid_rating(rating))
    {
        throw std::invalid_argument("Trying to add invalid rating");
    }

    cumulative_rating += rating;
    ratings_given++;
}
