#include <stdexcept>
#include "song.hpp"
#include "songwriter.hpp"

Song::Song(const char* title, SongWriter* songwriter, WrittenWork* lyrics,
        int length_in_seconds)
    : Work(title)
{
    if (songwriter == nullptr || lyrics == nullptr)
    {
        throw std::invalid_argument("Trying to create song with null writer/lyrics");
    }

    if (length_in_seconds <= 0)
    {
        throw std::invalid_argument("Trying to create song with non-positive length");
    }

    this->songwriter = songwriter;
    this->lyrics = lyrics;
    this->length_in_seconds = length_in_seconds;
}
