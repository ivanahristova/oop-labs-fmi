#include "tyre.hpp"
#include <stdexcept>

Tyre::Tyre(const char* id, const char* manufacturer, const char* description,
            int width, int profile, int rim_size)
    : CarPart(id, manufacturer, description)
{
    set_width(width);
    set_profile(profile);
    set_rim_size(rim_size);
}

void Tyre::set_width(int width)
{
    if (width < min_width || width > max_width)
    {
        throw std::invalid_argument("Trying to create tyre with invalid width");
    }

    this->width = width;
}

void Tyre::set_profile(int profile)
{
    if (profile < min_profile || profile > max_profile)
    {
        throw std::invalid_argument("Trying to create tyre with invalid profile");
    }

    this->profile = profile;
}

void Tyre::set_rim_size(int rim_size)
{
    if (rim_size < min_rim_size || rim_size > max_rim_size)
    {
        throw std::invalid_argument("Trying to create tyre with invalid rim size");
    }

    this->rim_size = rim_size;
}
