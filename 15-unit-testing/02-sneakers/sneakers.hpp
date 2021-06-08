#ifndef SNEAKERS_HPP
#define SNEAKERS_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <stdexcept>

class Sneakers
{
private:
    static const int max_string_len = 256;

    char manufacturer[max_string_len];
    char model[max_string_len];
    int price;
    int cumulative_rating;
    int ratings_given;
    int available;
    int sold;

public:
    Sneakers();
    Sneakers(const char* manufacturer, const char* model, int price,
            int available, int sold, int cumulative_rating = 0, int ratings_given = 0);

    static Sneakers from_text(char* line);

    const char* get_manufacturer() const;
    const char* get_model() const;
    int get_price() const;
    int get_cumulative_rating() const;
    int get_ratings_given() const;
    double get_average_rating() const;
    int get_available() const;
    int get_sold() const;

    void add_pair();
    void remove_pair();
    void add_rating(int rating);

    static bool is_valid_rating(int rating);

    friend std::ostream& operator<<(std::ostream& o_stream, const Sneakers& sneakers);
    friend std::istream& operator>>(std::istream& i_stream, Sneakers& sneakers);

    bool operator==(const Sneakers& other) const;

private:
    static void tokenize(char* line, char* tokens[], const int all_tokens_count);
    void change_quantity(int quantity_change);
};

#endif // SNEAKERS_HPP
