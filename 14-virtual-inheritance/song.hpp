#ifndef SONG_HPP
#define SONG_HPP

#include "work.hpp"
#include "singer.hpp"

class Singer;
class SongWriter;
class WrittenWork;

class Song : public Work
{
private:
    SongWriter* songwriter;
    WrittenWork* lyrics;
    int length_in_seconds;
public:
    Song(const char* title, SongWriter* songwriter, WrittenWork* lyrics,
            int length_in_seconds);
};

#endif // SONG_HPP
