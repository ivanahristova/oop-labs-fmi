#include "url.h"

const char* Url::default_url = "about:blank";

Url::Url(const char* url) 
{
    this->url = new char[strlen(url) + 1];
    strcpy(this->url, url);
}

Url::Url(const Url& other) 
{
    copy_from(other);
}

Url& Url::operator=(const Url& other) 
{
    if (this != &other)
    {
        free_memory();
        copy_from(other);
    }
    return *this;
}

Url::~Url() 
{
    free_memory();
}

void Url::free_memory() 
{
    delete[] url;
}

void Url::copy_from(const Url& other) 
{
    this->url = new char[strlen(other.url) + 1];
    strcpy(this->url, other.url);
}

const char* Url::get_url() const 
{
    return url;
}
