#include <stdexcept>
#include "sneaker-shop.hpp"
#include "exceptions/existing_sneakers_error.hpp"

void SneakerShop::require_valid_input_stream(std::istream& i_stream, const char* msg)
{
    if (i_stream.fail())
    {
        throw std::istream::failure(msg);
    }
}

void SneakerShop::require_valid_output_stream(std::ostream& o_stream, const char* msg)
{
    if (o_stream.fail())
    {
        throw std::ostream::failure(msg);
    }
}

void SneakerShop::reset_i_stream(std::istream& i_stream)
{
    i_stream.clear();
    i_stream.seekg(0, std::ios::beg);
}

void SneakerShop::reset_o_stream(std::ostream& o_stream)
{
    o_stream.clear();
    o_stream.seekp(0, std::ios::beg);
}

Sneakers SneakerShop::get_sneakers_by_model(std::istream& i_stream, const char* model_name)
{
    require_valid_input_stream(i_stream);

    const int buffer_size = 1024;
    char line[buffer_size];

    while (i_stream.getline(line, buffer_size))
    {
        Sneakers curr_sneakers = Sneakers::from_text(line);

        if (strcmp(curr_sneakers.get_model(), model_name) == 0)
        {
            reset_i_stream(i_stream);
            return curr_sneakers;
        }
    }

    reset_i_stream(i_stream);
    throw std::logic_error("Trying to get nonexisting sneakers");
}

Sneakers SneakerShop::get_sneakers_at_index(std::istream& i_stream, int index)
{
    if (index < 0)
    {
        throw std::invalid_argument("Trying to get sneakers at invalid index");
    }

    require_valid_input_stream(i_stream);

    const int buffer_size = 1024;
    char line[buffer_size];

    int curr_index = 0;

    Sneakers curr_sneakers;
    while (i_stream.getline(line, buffer_size) && curr_index <= index)
    {
        curr_sneakers = Sneakers::from_text(line);
        curr_index++;
    }

    reset_i_stream(i_stream);

    if (curr_index <= index)
    {
        throw std::out_of_range("Trying to get nonexisting sneakers: index out of range");
    }

    return curr_sneakers;
}

void SneakerShop::add_sneakers(std::istream& i_stream, std::ostream& o_stream, const Sneakers& sneakers)
{
    require_valid_output_stream(o_stream);

    Sneakers found_sneakers;
    try
    {
        found_sneakers = get_sneakers_by_model(i_stream, sneakers.get_model());
    }
    catch(const std::logic_error& e)
    {
        o_stream << sneakers;

        reset_i_stream(i_stream);
        reset_o_stream(o_stream);
        return;
    }

    reset_i_stream(i_stream);
    reset_o_stream(o_stream);
    throw existing_sneakers_error("Trying to add sneakers that already exist");
}

// combine adding and removing quantity (buying)
// quantity change: positive -> adding; negative -> buying
void SneakerShop::change_quantity_for_model(std::istream& i_stream, std::ostream& o_stream, const char* model_name,
                                int quantity_change)
{
    if (quantity_change == 0)
    {
        return;
    }

    require_valid_input_stream(i_stream);
    require_valid_output_stream(o_stream);

    const int buffer_size = 1024;
    char line[buffer_size];

    while (i_stream.getline(line, buffer_size))
    {
        Sneakers curr_sneakers = Sneakers::from_text(line);

        if (strcmp(curr_sneakers.get_model(), model_name) == 0)
        {
            try
            {
                if (quantity_change > 0)
                {
                    curr_sneakers.add_pair();
                }
                else
                {
                    curr_sneakers.remove_pair();
                }
            }
            catch(const std::out_of_range& e)
            {
                std::cerr << e.what() << '\n';
                reset_i_stream(i_stream);
                reset_o_stream(o_stream);
                return;
            }
        }

        o_stream << curr_sneakers << "\n";
    }

    reset_i_stream(i_stream);
    reset_o_stream(o_stream);
}

void SneakerShop::buy_pair_from_model(std::istream& i_stream, std::ostream& o_stream, const char* model_name)
{
    change_quantity_for_model(i_stream, o_stream, model_name, -1);
}

void SneakerShop::add_pair_from_model(std::istream& i_stream, std::ostream& o_stream, const char* model_name)
{
    change_quantity_for_model(i_stream, o_stream, model_name, 1);
}

void SneakerShop::add_rating_for_model(std::istream& i_stream, std::ostream& o_stream, const char* model_name,
                                    int rating)
{
    if (!Sneakers::is_valid_rating(rating))
    {
        throw std::invalid_argument("Trying to add invalid rating");
    }

    require_valid_input_stream(i_stream);
    require_valid_output_stream(o_stream);

    const int buffer_size = 1024;
    char line[buffer_size];
    while (i_stream.getline(line, buffer_size))
    {
        Sneakers curr_sneakers = Sneakers::from_text(line);

        if (strcmp(curr_sneakers.get_model(), model_name) == 0)
        {
            curr_sneakers.add_rating(rating);
        }

        o_stream << curr_sneakers << "\n";
    }

    reset_i_stream(i_stream);
    reset_o_stream(o_stream);
}


void SneakerShop::remove_model(std::istream& i_stream, std::ostream& o_stream, const char* model_name)
{
    require_valid_input_stream(i_stream);
    require_valid_output_stream(o_stream);

    const int buffer_size = 1024;
    char line[buffer_size];
    while (i_stream.getline(line, buffer_size))
    {
        Sneakers curr_sneakers = Sneakers::from_text(line);

        if (strcmp(curr_sneakers.get_model(), model_name) != 0)
        {
            o_stream << curr_sneakers << "\n";
        }
    }

    reset_i_stream(i_stream);
    reset_o_stream(o_stream);
}

void SneakerShop::swap(Sneakers& a, Sneakers& b)
{
    Sneakers tmp = a;
    a = b;
    b = tmp;
}

void SneakerShop::selection_sort(Sneakers* sneakers, const int sneakers_count, const int by_most_sold)
{
    // selection sort
    for (int i = 0; i < sneakers_count - 1; i++)
    {
        int max_index = i;

        for (int j = i + 1; j < sneakers_count; j++)
        {
            if (by_most_sold)
            {
                if (sneakers[j].get_sold() > sneakers[max_index].get_sold())
                {
                    max_index = j;
                }
            }
            else
            {
                if (sneakers[j].get_average_rating() > sneakers[max_index].get_average_rating())
                {
                    max_index = j;
                }
            }
        }

        swap(sneakers[i], sneakers[max_index]);
    }
}

// by_most_sold - true -> sorted by most sold
// else -> sorted by highest average rating
void SneakerShop::sort_models(std::istream& i_stream, std::ostream& o_stream, bool by_most_sold)
{
    require_valid_input_stream(i_stream);
    require_valid_output_stream(o_stream);

    const int buffer_size = 1024;
    char line[buffer_size];

    int capacity = 2, sneakers_count = 0;
    Sneakers* all_sneakers = new Sneakers[capacity];

    // read all sneakers into memory
    while (i_stream.getline(line, buffer_size))
    {
        Sneakers curr_sneakers = Sneakers::from_text(line);

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
        o_stream << all_sneakers[i] << "\n";
    }

    delete[] all_sneakers;
    reset_i_stream(i_stream);
    reset_o_stream(o_stream);
}
