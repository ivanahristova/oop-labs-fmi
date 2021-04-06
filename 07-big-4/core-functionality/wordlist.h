#ifndef WORDLIST_H
#define WORDLIST_H

#include "../helper/constants.h"
#include "../helper/helper-functions.h"
#include <iostream>
#include <fstream>
#include <cstring>

class Wordlist
{
private:
    char** words;
    int capacity;
    int count;

    void free();
    void copy(const Wordlist& other);
    void resize();

public:
    Wordlist();
    Wordlist(const Wordlist& other);
    Wordlist& operator=(const Wordlist& other);
    ~Wordlist();

    void add_word(const char* word);
    void save() const;
    void open();
    const char* get_word() const;

};

#endif
