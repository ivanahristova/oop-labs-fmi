#ifndef WRITTEN_WORK_HPP
#define WRITTEN_WORK_HPP

#include "work.hpp"

class WrittenWork : public Work
{
private:
    int length;
public:
    WrittenWork(const char* title, int length);
    int get_length_in_seconds();
};

#endif // WRITTEN_WORK_HPP
