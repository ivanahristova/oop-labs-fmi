#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

template <typename T>
class Stack
{
private:
    static const int max_size = 8;
    T* elements;
    int count;
    int capacity;

public:
    Stack();
    Stack(const Stack<T>& other);
    Stack<T>& operator=(const Stack<T>& other);
    ~Stack();

    T top(); // return the top element
    void pop(); // delete the top elements
    void push(const T& element); // add element to the top of the stack
    bool empty() const;
    int size() const; // occupied memory
    void erase();

private:
    void copy_from(const Stack<T>& other);
    void free_memory();
    void resize(bool bigger = true);

};

template <typename T>
Stack<T>::Stack()
    : capacity(max_size), count(0)
{
    elements = new T[capacity];
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
    copy_from(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other)
    {
        free_memory();
        copy_from(other);
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    free_memory();
}

template <typename T>
T Stack<T>::top()
{
    if (count == 0)
    {
        throw std::out_of_range("Top is called on an empty stack.");
    }

    return elements[count - 1];
}

template <typename T>
void Stack<T>::pop()
{
    if (count == 0)
    {
        throw std::out_of_range("Pop is called on an empty stack.");
    }

    count--;

    if (count < capacity / 2)
    {
        resize(false);
    }
}

template <typename T>
void Stack<T>::push(const T& element)
{
    if (count == capacity)
    {
        resize();
    }

    elements[count] = element;
    count++;
}

template <typename T>
bool Stack<T>::empty() const
{
    return count == 0;
}

template <typename T>
int Stack<T>::size() const
{
    return count;
}

template <typename T>
void Stack<T>::copy_from(const Stack<T>& other)
{
    this->count = other.count;
    this->capacity = other.capacity;

    this->elements = new T[capacity];
    for (int i = 0; i < count; i++)
    {
        this->elements[i] = other.elements[i];
    }
}

template <typename T>
void Stack<T>::free_memory()
{
    delete[] elements;
}

template <typename T>
void Stack<T>::resize(bool bigger)
{
    if (bigger)
    {
        capacity *= 2;
    }
    else
    {
        capacity /= 2;
    }

    T* temp = elements;
    elements = new T[capacity];
    for (int i = 0; i < count; i++)
    {
        elements[i] = temp[i];
    }

    delete[] temp;
}

template <typename T>
void Stack<T>::erase()
{
    free_memory();

    count = 0;
    capacity = max_size;
    elements = new T[capacity];
}


#endif
