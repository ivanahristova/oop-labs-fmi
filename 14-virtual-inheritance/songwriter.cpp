#include "songwriter.hpp"
#include "artist.hpp"


SongWriter::SongWriter(const char* name)
    : Artist(name), Writer(name), Singer(name)
{

}
