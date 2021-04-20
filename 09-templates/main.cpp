#include <iostream>
#include <cassert>

#include "fmi_restaurant.hpp"
#include "meal.hpp"
#include "queue.hpp"

template <typename T>
T generic_min(const T* arr, int len);

void demo_int_queue();
void demo_generic_min();
void demo_fmi_restaurant();

int main()
{
    // demo_generic_min();
    // demo_int_queue();

    demo_fmi_restaurant();
}

void demo_fmi_restaurant()
{
    FMIRestaurant restaurant;

    Order order1(Meal::Shopska, 200, "Studentski grad");
    restaurant.place_order(order1);

    Order order2(Meal::Rice, 300, "Mladost 1");
    restaurant.place_order(order2);

    Order order3(Meal::Chicken, 400, "Mladost 4");
    restaurant.place_order(order3);

    const Queue<Order>& orders_queue = restaurant.get_order_queue();

    Order received_order1 = restaurant.send_next_order();
    std::cout << received_order1.get_name_of_meal()
        << ", " << received_order1.get_grams()
        << "g, " << received_order1.get_address() << "\n";

}

template <typename T>
T generic_min(const T* arr, int len)
{
    assert(len > 1);

    T min_found = arr[0];

    for (int i = 1; i < len; i++)
    {
        if (arr[i] < min_found)
        {
            min_found = arr[i];
        }
    }

    return min_found;
}

void demo_generic_min()
{
    char char_arr[7] = {'c', 'b', 'g', 'd', 'f', 'e', 'a'};
    std::cout << generic_min(char_arr, 7) << "\n";

    int int_arr[5] = {2, 5, 1, 7, 3};
    std::cout << generic_min(int_arr, 4) << "\n";
}

void demo_int_queue()
{
    Queue<int> q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(5);
    q1.enqueue(7);
    q1.enqueue(9);
    q1.enqueue(12);

    // operator=
    Queue<int> q2;
    q2 = q1;

    while (!q2.is_empty())
    {
        std::cout << q2.dequeue() << "\n";
    }
}
