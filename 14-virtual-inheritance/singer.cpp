#include "artist.hpp"
#include "singer.hpp"
#include "song.hpp"

Singer::Singer(const char* name)
    : Artist(name)
{

}

Song Singer::produce_song(const char* title, SongWriter* songwriter, WrittenWork* lyrics,
            int length_in_seconds)
{
    return Song(title, songwriter, lyrics, length_in_seconds);
}
