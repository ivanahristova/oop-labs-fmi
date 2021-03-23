#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>

const int max_string_len = 256;

struct Sneakers
{
    char manufacturer[max_string_len];
    char model[max_string_len];
    int price;
    int cumulative_rating;
    int ratings_given;
    int available;
    int sold;
};

void output_to_stream(std::ostream& o_stream, const Sneakers& sneakers)
{
    const char delimiter = ' ';
    o_stream << sneakers.manufacturer << delimiter;
    o_stream << sneakers.model << delimiter;
    o_stream << sneakers.price << delimiter;
    o_stream << sneakers.cumulative_rating << delimiter;
    o_stream << sneakers.ratings_given << delimiter;
    o_stream << sneakers.available << delimiter;
    o_stream << sneakers.sold << '\n';
}

bool add_sneakers(const char* filename, const Sneakers& sneakers)
{
    std::ofstream of_stream;
    of_stream.open(filename, std::ios::app);

    if (!of_stream.is_open())
    {
        return false;
    }

    output_to_stream(of_stream, sneakers);

    of_stream.close();

    return true;
}

void tokenize(char* line, char* tokens[], const int all_tokens_count)
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

void initialize_from_text(Sneakers& sneakers, char* tokens[])
{
    const int token_index_manufacturer = 0;
    const int token_index_model = 1;
    const int token_index_price = 2;
    const int token_index_cumulative_rating = 3;
    const int token_index_ratings_given = 4;
    const int token_index_available = 5;
    const int token_index_sold = 6;

    strcpy(sneakers.manufacturer, tokens[token_index_manufacturer]);
    strcpy(sneakers.model, tokens[token_index_model]);
    sneakers.price = atoi(tokens[token_index_price]);
    sneakers.cumulative_rating = atoi(tokens[token_index_cumulative_rating]);
    sneakers.ratings_given = atoi(tokens[token_index_ratings_given]);
    sneakers.available = atoi(tokens[token_index_available]);
    sneakers.sold = atoi(tokens[token_index_sold]);
}

// combine adding and removing quantity (buying)
// quantity change: positive -> adding; negative -> buying
bool change_quantity_for_model(const char* db_name, const char* model_name, int quantity_change)
{
    if (quantity_change == 0)
    {
        return true;
    }

    const char* temp_filename = "sneakers_tmp.db";

    std::ofstream of_stream(temp_filename);
    std::ifstream if_stream(db_name);

    if (!of_stream)
    {
        std::cerr << "Could not open temporary database file\n";
        return false;
    }
    if (!if_stream)
    {
        std::cerr << "Could not open database file for reading\n";
        return false;
    }

    const int buffer_size = 1024;
    char line[buffer_size];

    const int all_tokens_count = 7;
    char* tokens[all_tokens_count];

    while (if_stream.getline(line, buffer_size))
    {
        tokenize(line, tokens, all_tokens_count);

        Sneakers curr_sneakers;
        initialize_from_text(curr_sneakers, tokens);

        if (strcmp(curr_sneakers.model, model_name) == 0)
        {
            // trying to buy more than available
            if (curr_sneakers.available + quantity_change < 0)
            {
                return false;
            }

            curr_sneakers.available += quantity_change;
        }

        output_to_stream(of_stream, curr_sneakers);
    }

    rename(temp_filename, db_name);
    return true;
}

bool buy_pair_from_model(const char* db_name, const char* model_name)
{
    return change_quantity_for_model(db_name, model_name, -1);
}

bool add_pair_from_model(const char* db_name, const char* model_name)
{
    return change_quantity_for_model(db_name, model_name, 1);
}

bool add_rating_for_model(const char* db_name, const char* sneakers_model, int rating)
{
    const int min_rating = 1;
    const int max_rating = 10;
    if (rating < min_rating || rating > max_rating)
    {
        return false;
    }

    const char* temp_filename = "sneakers_tmp.db";

    std::ifstream if_stream(db_name);
    std::ofstream of_stream(temp_filename);

    if (!if_stream)
    {
        std::cout << "Error while trying to load database\n";
        return false;
    }
    if (!of_stream)
    {
        std::cout << "Error while trying to set up a temporary database file\n";
        return false;
    }

    const int all_tokens_count = 7;
    char* tokens[all_tokens_count];

    const int buffer_size = 1024;
    char line[buffer_size];
    while (if_stream.getline(line, buffer_size))
    {
        tokenize(line, tokens, all_tokens_count);

        Sneakers curr_sneakers;
        initialize_from_text(curr_sneakers, tokens);

        if (strcmp(curr_sneakers.model, sneakers_model) == 0)
        {
            curr_sneakers.cumulative_rating += rating;
            curr_sneakers.ratings_given++;
        }

        output_to_stream(of_stream, curr_sneakers);
    }

    rename(temp_filename, db_name);
    return true;
}

bool remove_model(const char* db_name, const char* sneakers_model)
{
    const char* temp_filename = "sneakers_tmp.db";

    std::ifstream if_stream(db_name);
    std::ofstream of_stream(temp_filename);

    if (!if_stream)
    {
        std::cout << "Error while trying to load database\n";
        return false;
    }
    if (!of_stream)
    {
        std::cout << "Error while trying to set up a temporary database file\n";
        return false;
    }

    const int all_tokens_count = 7;
    char* tokens[all_tokens_count];

    const int buffer_size = 1024;
    char line[buffer_size];
    while (if_stream.getline(line, buffer_size))
    {
        tokenize(line, tokens, all_tokens_count);

        Sneakers curr_sneakers;
        initialize_from_text(curr_sneakers, tokens);

        if (strcmp(curr_sneakers.model, sneakers_model) != 0)
        {
            output_to_stream(of_stream, curr_sneakers);
        }
    }

    rename(temp_filename, db_name);
    return true;
}

double get_average_rating(const Sneakers& sneakers)
{
    if (sneakers.ratings_given < 1)
    {
        return 0;
    }

    return 1.0 * sneakers.cumulative_rating / sneakers.ratings_given;
}

void swap(Sneakers* a, Sneakers* b)
{
    Sneakers tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_sort(Sneakers* sneakers, const int sneakers_count, const int by_most_sold)
{
    // selection sort
    for (int i = 0; i < sneakers_count - 1; i++)
    {
        int max_index = i;

        for (int j = i + 1; j < sneakers_count; j++)
        {
            if (by_most_sold)
            {
                if (sneakers[j].sold > sneakers[max_index].sold)
                {
                    max_index = j;
                }
            }
            else
            {
                if (get_average_rating(sneakers[j]) > get_average_rating(sneakers[max_index]))
                {
                    max_index = j;
                }
            }
        }

        swap(&sneakers[i], &sneakers[max_index]);
    }
}

// by_most_sold - true -> sorted by most sold
// else -> sorted by highest average rating
bool sort_models(const char* filename, bool by_most_sold)
{
    const char* temp_filename = "sneakers_tmp.db";

    std::ofstream of_stream(temp_filename);
    std::ifstream if_stream(filename);

    if (!of_stream)
    {
        std::cerr << "Could not open temporary database file\n";
        return false;
    }
    if (!if_stream)
    {
        std::cerr << "Could not open database file for reading\n";
        return false;
    }

    const int buffer_size = 1024;
    char line[buffer_size];

    const int all_tokens_count = 7;
    char* tokens[all_tokens_count];

    int capacity = 2, sneakers_count = 0;
    Sneakers* all_sneakers = new Sneakers[capacity];

    // read all sneakers into memory
    while (if_stream.getline(line, buffer_size))
    {
        tokenize(line, tokens, all_tokens_count);

        Sneakers curr_sneakers;
        initialize_from_text(curr_sneakers, tokens);

        // resize is necessary
        if (sneakers_count >= capacity)
        {
            Sneakers* new_sneakers = new Sneakers[capacity * 2];
            for (int i = 0; i < sneakers_count; i++)
            {
                new_sneakers[i] = all_sneakers[i];
            }

            delete[] all_sneakers;
            all_sneakers = new_sneakers;

            capacity *= 2;
        }

        all_sneakers[sneakers_count++] = curr_sneakers;
    }

    selection_sort(all_sneakers, sneakers_count, by_most_sold);

    for (int i = 0; i < sneakers_count; i++)
    {
        output_to_stream(of_stream, all_sneakers[i]);
    }

    rename(temp_filename, filename);

    delete[] all_sneakers;
    return true;
}

int main()
{
    const char* db_name = "sneakers.db";

    Sneakers nike;
    strcpy(nike.manufacturer, "Nike");
    strcpy(nike.model, "Model4");
    nike.available = 30;
    nike.cumulative_rating = 0;
    nike.price = 100;
    nike.sold = 0;
    nike.ratings_given = 0;

    // add_sneakers(db_name, nike);
    // buy_pair_from_model(db_name, "Model");
    // add_pair_from_model(db_name, "Model");
    // add_rating_for_model(db_name, "Model", 7);
    // remove_model(db_name, "Model5");
    sort_models(db_name, false);

    return 0;
}
