#include <cstring>
#include "artist.hpp"
#include "work.hpp"

Artist::Artist(const char* name)
{
    const int name_len = strlen(name);
    strncpy(this->name, name, 100);
    const int terminator_index = name_len < 199 ? name_len : 199;
    this->name[terminator_index] = '\0';

    this->followers = 0;
    this->released_works = 0;
}

const char* Artist::get_name()
{
    return name;
}

int Artist::get_released_works()
{
    return released_works;
}

int Artist::get_followers()
{
    return followers;
}

void Artist::gain_follower()
{
    this->followers++;
}

Work Artist::produce_work(const char* title)
{
    return Work(title);
}
