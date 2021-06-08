#ifndef EXISTING_SNEAKERS_ERROR_HPP
#define EXISTING_SNEAKERS_ERROR_HPP

#include <stdexcept>

class existing_sneakers_error : public std::logic_error
{
public:
    existing_sneakers_error(const char* msg) : std::logic_error(msg)
    {}
};

#endif // EXISTING_SNEAKERS_ERROR_HPP
