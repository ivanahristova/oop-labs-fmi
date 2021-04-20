#ifndef FMI_RESTAURANT_HPP
#define FMI_RESTAURANT_HPP

#include "order.hpp"
#include "queue.hpp"

class FMIRestaurant
{
private:
    Queue<Order> orders_queue;

public:
    void place_order(const Order& order);
    const Queue<Order>& get_order_queue() const;
    Order send_next_order();
};

#endif // FMI_RESTAURANT_HPP
