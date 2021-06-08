#ifndef SONGWRITER_HPP
#define SONGWRITER_HPP

#include "writer.hpp"
#include "singer.hpp"

class SongWriter : virtual public Writer, virtual public Singer
{
private:

public:
    SongWriter(const char* name);
};

#endif // SONGWRITER_HPP
