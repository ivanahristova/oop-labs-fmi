#ifndef WRITER_HPP
#define WRITER_HPP

#include "artist.hpp"
#include "written_work.hpp"

class Writer : virtual public Artist
{
private:
    int cumulative_length;
    int written_works_produced;
public:
    Writer(const char* name);
    double average_length();
    WrittenWork produce_written_work(const char* title, int length);
};

#endif // WRITER_HPP
