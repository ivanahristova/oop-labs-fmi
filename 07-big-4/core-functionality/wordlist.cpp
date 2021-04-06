#include "wordlist.h"

void Wordlist::free()
{
    //char**
    // delete

    for (int i = 0; i < capacity; i++)
    {
        // if (words[i] == nullptr)
        // {
        //     continue;
        // }
        delete words[i];
    }

    delete[] words;
}

void Wordlist::copy(const Wordlist& other)
{
    this->capacity = other.capacity;
    this->count = other.count;

    // char**
    this->words = new char*[capacity];
    for (int i = 0; i < capacity; i++)
    {
        if (other.words[i] == nullptr)
        {
            words[i] = nullptr;
            continue;
        }
        this->words[i] = new char[strlen(other.words[i]) + 1];
        strcpy(this->words[i], other.words[i]);
    }

}

Wordlist::Wordlist() : capacity(MAX_INITIAL_CAPACITY), count(0)
{
    words = new char*[capacity];
    for (int i = 0; i < capacity; i++)
    {
        words[i] = nullptr;
    }
}

Wordlist::Wordlist(const Wordlist& other)
{
    copy(other);
}

Wordlist& Wordlist::operator=(const Wordlist& other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

Wordlist::~Wordlist()
{
    free();
}

void Wordlist::add_word(const char* word)
{
    if (capacity == count)
    {
        resize();
    }

    words[count] = new char[strlen(word) + 1];
    strcpy(words[count], word);
    count++;
}

void Wordlist::save() const
{
    std::ofstream o_file("files/word.txt");
    if (o_file.fail())
    {
        return;
    }

    for (int i = 0; i < capacity; i++)
    {
        if (words[i] != nullptr)
        {
            o_file << words[i] << '\n';
        }
    }

    o_file.close();
}

void Wordlist::open()
{
    std::ifstream i_file("files/word.txt");
    if (i_file.fail())
    {
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (i_file.peek() != EOF)
    {
        i_file.getline(word, MAX_WORD_LENGTH);
        add_word(word);
    }

    i_file.close();
}

const char* Wordlist::get_word() const
{
    if (count == 0)
    {
        return nullptr;
    }

    int index = get_random_number(count);
    return words[index];
}

void Wordlist::resize()
{
    int new_capacity = capacity * 2;
    int new_count = count;
    char** new_words = new char*[new_capacity];

    for (int i = 0; i < capacity; i++)
    {
        if (words[i] != nullptr)
        {
            new_words[i] = new char[strlen(words[i]) + 1];
            strcpy(new_words[i], words[i]);
        }
        else
        {
            new_words[i] = nullptr;
        }
    }

    for (int i = capacity; i < new_capacity; i++)
    {
        new_words[i] = nullptr;
    }

    free();
    capacity = new_capacity;
    count = new_count;
    words = new_words;
}
