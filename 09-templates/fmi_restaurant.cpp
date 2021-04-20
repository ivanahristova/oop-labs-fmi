#include "fmi_restaurant.hpp"

void FMIRestaurant::place_order(const Order& order)
{
    orders_queue.enqueue(order);
}

const Queue<Order>& FMIRestaurant::get_order_queue() const
{
    return orders_queue;
}

Order FMIRestaurant::send_next_order()
{
    return orders_queue.dequeue();
}
