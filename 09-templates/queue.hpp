#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>

template <typename T>
class Queue
{
private:
    static const int initial_capacity = 4;

    T* arr;

    int count;
    int capacity;

    int front_index;
    int rear_index;

    void copy_from(const Queue<T>& other);
    void free_memory();
    void resize();

public:
    Queue();
    Queue(const Queue<T>& other);
    Queue<T>& operator=(const Queue<T>& other);
    ~Queue();

    bool is_empty() const;
    void enqueue(T el);
    T dequeue();
    T& peek();
};

template <typename T>
Queue<T>::Queue()
{
    arr = new T[initial_capacity];

    count = 0;
    capacity = initial_capacity;

    front_index = rear_index = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other)
{
    copy_from(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if (this != &other)
    {
        free_memory();
        copy_from(other);
    }

    return *this;
}

template <typename T>
Queue<T>::~Queue()
{
    free_memory();
}

template <typename T>
void Queue<T>::copy_from(const Queue<T>& other)
{
    arr = new T[other.capacity];

    for (int i = other.front_index; i != other.rear_index; (++i) %= other.capacity)
    {
        arr[i] = other.arr[i];
    }

    count = other.count;
    capacity = other.capacity;
    front_index = other.front_index;
    rear_index = other.rear_index;
}

template <typename T>
void Queue<T>::free_memory()
{
    delete[] arr;
    count = capacity = 0;
}

template <typename T>
void Queue<T>::resize()
{
    T* bigger = new T[capacity * 2];

    for (int i = 0; i < capacity; i++)
    {
        bigger[i] = dequeue();
    }

    front_index = 0;
    rear_index = capacity;
    count = capacity;

    capacity *= 2;
    delete[] arr;

    arr = bigger;
}

template <typename T>
bool Queue<T>::is_empty() const
{
    return count == 0;
}

template <typename T>
void Queue<T>::enqueue(T el)
{
    if (count == capacity)
    {
        resize();
    }

    arr[rear_index] = el;
    rear_index++;
    rear_index = rear_index % capacity;

    count++;
}

template <typename T>
T Queue<T>::dequeue()
{
    if (count == 0)
    {
        // we leave it like this for now
        throw std::exception();
    }

    T front_el = arr[front_index];

    count--;

    front_index++;
    front_index = front_index % capacity;

    return front_el;
}

template <typename T>
T& Queue<T>::peek()
{
    if (count == 0)
    {
        // we leave it like this for now
        throw std::exception();
    }

    return arr[front_index];
}

#endif // QUEUE_HPP
