#include <iostream>
#include <cstring>
#include "binary_num.hpp"

BinaryNum::BinaryNum()
    : digits_capacity(1), digits_count(1)
{
    std::cout << "Constr\n";

    digits = new char[digits_capacity + 1];

    digits[0] = '0';
    digits[1] = '\0';
}

BinaryNum::BinaryNum(const char* digits_str)
    : digits_capacity(get_needed_capacity(digits_str)), digits_count(0)
{
    std::cout << "Constr char*\n";

    int i = get_start_of_number(digits_str);

    if (i == -1)
    {
        // same as default
        digits = new char[digits_capacity + 1];

        digits[0] = '0';
        digits[1] = '\0';
        return;
    }

    digits = new char[digits_capacity];

    const int len = strlen(digits_str);
    while (i < len && is_valid_bin_digit(digits_str[i]))
    {
        digits[digits_count++] = digits_str[i];
        i++;
    }

    digits[digits_count] = '\0';
}

BinaryNum::BinaryNum(const BinaryNum& other)
{
    std::cout << "Copy constr\n";
    copy_from(other);
}

BinaryNum& BinaryNum::operator=(const BinaryNum& other)
{
    std::cout << "Copy assign\n";
    if (this != &other)
    {
        free_memory();
        copy_from(other);
    }

    return *this;
}

BinaryNum::~BinaryNum()
{
    std::cout << "Destr\n";
    free_memory();
}

BinaryNum::BinaryNum(BinaryNum&& other) noexcept
{
    std::cout << "Move constr\n";

    digits_capacity = other.digits_capacity;
    digits_count = other.digits_count;
    digits = other.digits;

    other.digits = nullptr;
}

BinaryNum& BinaryNum::operator=(BinaryNum&& other) noexcept
{
    std::cout << "Move assign\n";

    free_memory();

    digits_capacity = std::move(other.digits_capacity);
    digits_count = std::move(other.digits_count);
    digits = std::move(other.digits);

    other.digits = nullptr;

    return *this;
}

bool BinaryNum::is_valid_bin_digit(char ch)
{
    return ch == '0' || ch == '1';
}

int BinaryNum::get_needed_capacity(const char* digits_str)
{
    int capacity = 1;
    int count = 0;

    const int len = strlen(digits_str);
    int i = get_start_of_number(digits_str);
    while (i < len && is_valid_bin_digit(digits_str[i]))
    {
        i++;
        count++;

        if (count >= capacity)
        {
            capacity *= 2;
        }
    }

    return capacity;
}

int BinaryNum::get_start_of_number(const char* digits_str)
{
    int i = 0;

    const int len = strlen(digits_str);
    while (i < len && digits_str[i] != '1')
    {
        i++;
    }

    if (i == len)
    {
        return -1;
    }

    return i;
}

// Assumes that memory has been freed
void BinaryNum::copy_from(const BinaryNum& other)
{
    digits_capacity = other.digits_capacity;
    digits_count = other.digits_count;

    digits = new char[digits_capacity];
    strncpy(digits, other.digits, other.digits_count);

    digits[digits_count] = '\0';
}

void BinaryNum::free_memory()
{
    delete[] digits;
}

BinaryNum BinaryNum::operator&(const BinaryNum& other)
{
    int size_smaller = (digits_count < other.digits_count) ? digits_count : other.digits_count;
    int size_bigger = (digits_count >= other.digits_count) ? digits_count : other.digits_count;

    char* result_str = new char[size_smaller + 1];

    int cursor_lhs = digits_count - 1;
    int cursor_rhs = other.digits_count - 1;
    int count_res = 0;

    for (int i = 0; i < size_smaller; i++)
    {
        bool lhs_digit = (digits[cursor_lhs--]) - '0';
        bool rhs_digit = (other.digits[cursor_rhs--]) - '0';

        result_str[size_smaller - count_res - 1] = (lhs_digit & rhs_digit) + '0';
        count_res++;
    }

    result_str[size_smaller] = '\0';

    BinaryNum result(result_str);
    delete[] result_str;

    return result;
}

const char* BinaryNum::get_str()
{
    return digits;
}

// TODO: operator<<, operator>>
