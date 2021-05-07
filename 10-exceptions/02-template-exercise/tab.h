#ifndef TAB_HPP
#define TAB_HPP

#include "stack.hpp"
#include "url.h"
#include <iostream>
#include <cstring>

class Tab
{
private:
    Url current_url;
    Stack<Url> past;
    Stack<Url> future;

public:
    void load(const char* url);
    void back();
    void forward();
    const char* get_url() const;
};

#endif