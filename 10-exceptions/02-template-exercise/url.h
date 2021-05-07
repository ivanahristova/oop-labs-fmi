#ifndef URL_H
#define URL_H

#include <cstring>

class Url
{
private:
    static const char* default_url;
    char* url;

public:
    Url(const char* url = default_url);
    Url(const Url& other);
    Url& operator=(const Url& other);
    ~Url();

    const char* get_url() const;

private:
    void free_memory();
    void copy_from(const Url& other);
};

#endif