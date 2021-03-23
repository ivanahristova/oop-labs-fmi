#include <iostream>
#include <fstream>

int file_length(const char* filename)
{
    std::ifstream i_file(filename);

    if (!i_file.is_open())
    {
        return -1;
    }

    int len = -1; // eofbit
    while(!i_file.eof())
    {
        char c;
        //i_file >> c; // cin >> a; doesn't take whitespaces into account
        i_file.get(c);
        len++;
    }

    i_file.close();
    return len;
}

int file_length_ver2(const char* filename)
{
    std::ifstream i_file;
    i_file.open(filename);

    if (!i_file.is_open())
    {
        return -1;
    }

    i_file.seekg(0, std::ios::end);
    int len = i_file.tellg();
    i_file.close();
    return len;
}

int main()
{
    std::cout << file_length("filename.txt") << "\n";
    std::cout << file_length_ver2("filename.txt") << "\n";
}
