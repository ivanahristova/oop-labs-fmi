#ifndef BINARY_NUM_HPP
#define BINARY_NUM_HPP

#include <iostream>

class BinaryNum
{
private:
    char* digits;
    int digits_count;
    int digits_capacity;

public:
    BinaryNum();
    BinaryNum(const char* digits_str);

    // Big 5
    BinaryNum(const BinaryNum& other);
    BinaryNum(BinaryNum&& other) noexcept;
    BinaryNum& operator=(const BinaryNum& other);
    BinaryNum& operator=(BinaryNum&& other) noexcept;
    ~BinaryNum();

    BinaryNum operator&(const BinaryNum& other);

    const char* get_str();

private:
    void copy_from(const BinaryNum& other);
    void free_memory();
    int get_needed_capacity(const char* digits_str);
    bool is_valid_bin_digit(char ch);
    int get_start_of_number(const char* digits_str);

    friend std::ostream& operator<<(std::ostream& o_stream, const BinaryNum& num);
};

std::ostream& operator<<(std::ostream& o_stream, const BinaryNum& num);

#endif // BINARY_NUM_HPP
