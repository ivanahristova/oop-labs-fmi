#ifndef SNEAKER_SHOP_HPP
#define SNEAKER_SHOP_HPP

#include "sneakers.hpp"

class SneakerShop
{
private:
    void change_quantity_for_model(std::istream& i_stream, std::ostream& o_stream,
                                const char* model_name, int quantity_change);

    void swap(Sneakers& a, Sneakers& b);
    void selection_sort(Sneakers* sneakers, const int sneakers_count, const int by_most_sold);

    void require_valid_input_stream(std::istream& i_stream,
                                    const char* msg = "Output stream is not in a valid state");
    void require_valid_output_stream(std::ostream& o_stream,
                                    const char* msg = "Input stream is not in a valid state");

    void reset_i_stream(std::istream& i_stream);
    void reset_o_stream(std::ostream& o_stream);

public:
    void add_sneakers(std::istream& i_stream, std::ostream& o_stream, const Sneakers& sneakers);
    void buy_pair_from_model(std::istream& i_stream, std::ostream& o_stream, const char* model_name);
    void add_pair_from_model(std::istream& i_stream, std::ostream& o_stream, const char* model_name);
    void add_rating_for_model(std::istream& i_stream, std::ostream& o_stream, const char* model_name, int rating);
    void remove_model(std::istream& i_stream, std::ostream& o_stream, const char* model_name);
    void sort_models(std::istream& i_stream, std::ostream& o_stream, bool by_most_sold);
    Sneakers get_sneakers_by_model(std::istream& i_stream, const char* model_name);
    Sneakers get_sneakers_at_index(std::istream& i_stream, int index);
};

#endif // SNEAKER_SHOP_HPP
