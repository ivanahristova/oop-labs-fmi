#include "helpers.hpp"

void get_last_line(std::istream& i_stream, char buffer[])
{
    i_stream.seekg(-2, std::ios::end);

    bool found_last_line = false;
    while (!found_last_line)
    {
        char ch;
        i_stream.get(ch);

        if (i_stream.tellg() <= 1)
        {
            i_stream.seekg(0);
            found_last_line = true;
        }
        else if (ch == '\n')
        {
            found_last_line = true;
        }
        else
        {
            i_stream.seekg(-2, std::ios::cur);
        }
    }

    i_stream.getline(buffer, 3000);
}
