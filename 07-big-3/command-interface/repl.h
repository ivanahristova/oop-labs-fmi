#ifndef REPL_H
#define REPL_H

#include "../core-functionality/wordlist.h"

class REPL
{
private:
    Wordlist wordlist;

    bool validate_command(const char* command) const;
    void analyse_command(const char* command);

    void print_command_error_message() const;

    void print_get_word_result(const char* word) const;
    void print_save_result() const;
    void print_open_result() const;

    void print_help() const;

public:
    void run();

};

#endif
