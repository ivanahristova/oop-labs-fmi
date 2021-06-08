#include "written_work.hpp"
#include <stdexcept>

WrittenWork::WrittenWork(const char* title, int length)
    : Work(title)
{
    if (length <= 0)
    {
        throw std::invalid_argument("Written work length must be positive");
    }

    this->length = length;
}

int WrittenWork::get_length_in_seconds()
{
    return length;
}
