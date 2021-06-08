#ifndef ARTIST_HPP
#define ARTIST_HPP

#include "work.hpp"

class Artist
{
private:
    char name[100];
    int released_works;
    int followers;
public:
    const char* get_name();
    int get_released_works();
    int get_followers();
    void gain_follower();
    Work produce_work(const char* title);

    Artist(const char* name);
    virtual ~Artist() {}
};

#endif // ARTIST_HPP
