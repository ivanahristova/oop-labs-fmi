#ifndef TYPE_HPP
#define TYPE_HPP

#include "car-part.hpp"

class Tyre : public CarPart
{
private:
    static const int min_width = 155;
    static const int max_width = 365;

    static const int min_profile = 30;
    static const int max_profile = 80;

    static const int min_rim_size = 13;
    static const int max_rim_size = 21;

    int width;
    int profile;
    int rim_size;

    void set_width(int width);
    void set_profile(int profile);
    void set_rim_size(int rim_size);
public:
    Tyre(const char* id, const char* manufacturer, const char* description,
         int width, int profile, int rim_size);
};

#endif // TYPE_HPP
