#include <cstring>
#include <stdexcept>
#include "artist.hpp"
#include "writer.hpp"

Writer::Writer(const char* name)
    : Artist(name)
{
    cumulative_length = 0;
    written_works_produced = 0;
}

WrittenWork Writer::produce_written_work(const char* title, int length)
{
    WrittenWork work(title, length);

    cumulative_length += length;
    written_works_produced++;

    return work;
}

double Writer::average_length()
{
    if (written_works_produced < 1)
    {
        return 0.0;
    }
    return 1.0 * cumulative_length / written_works_produced;
}
