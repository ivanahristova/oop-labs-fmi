#ifndef SINGER_HPP
#define SINGER_HPP

#include "artist.hpp"
#include "song.hpp"
class Song;
class SongWriter;
class WrittenWork;

class Singer : virtual public Artist
{
private:
public:
    Singer(const char* name);
    Song produce_song(const char* title, SongWriter* songwriter, WrittenWork* lyrics,
            int length_in_seconds);
};

#endif // SINGER_HPP
