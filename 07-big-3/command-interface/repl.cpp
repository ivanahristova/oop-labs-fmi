#include "repl.h"

void REPL::run()
{
    char command[MAX_COMMAND_LENGTH];
    bool passed = true;
    do {
        std::cout << ">>> ";
        std::cin.getline(command, MAX_COMMAND_LENGTH);
        if (!validate_command(command))
        {
            print_command_error_message();
            continue;
        }
        if (strcmp(command, "exit") == 0)
        {
            wordlist.save();
            passed = false;
        }
        else
        {
            analyse_command(command);
        }
    } while (passed);
}

bool REPL::validate_command(const char* command) const
{
    int command_length = strlen(command);
	int end = command_length - 1;
	if (command[0] == ' ' || command[0] == '\t' ||
		command[end] == ' ' || command[end] == '\t')
	{
		return false;
	}
	for (int i = 0; i < end; i++)
	{
		if (command[i] == ' ' && command[i + 1] == ' ' || command[i] == '\t')
		{
			return false;
		}
	}
	return true;
}

void REPL::analyse_command(const char* command)
{
    char arg0[MAX_COMMAND_LENGTH];
    get_argument(command, arg0);
    int command_index = strlen(arg0) + 1;

    if (strcmp(arg0, "add") == 0)
    {
        char arg1[MAX_COMMAND_LENGTH];
        get_argument(command + command_index, arg1);
        wordlist.add_word(arg1);
    }
    else if (strcmp(arg0, "get-word") == 0)
    {
        char word[MAX_WORD_LENGTH];
        const char* ptr_to_word = wordlist.get_word();
        print_get_word_result(ptr_to_word);
    }
    else if (strcmp(arg0, "save") == 0)
    {
        wordlist.save();
        print_save_result();
    }
    else if (strcmp(arg0, "open") == 0)
    {
        wordlist.open();
        print_open_result();
    }
    else if (strcmp(arg0, "help") == 0)
    {
        print_help();
    }
    else
    {
        print_command_error_message();
    }
}

void REPL::print_command_error_message() const
{
    std::cout << "Use a single whitespace to seperate arguments." << '\n';
    std::cout << "The command must not conatain leading or trailing whitespaces." << '\n';
    std::cout << "Use 'help' for more information." << '\n';
}

void REPL::print_get_word_result(const char* ptr_to_word) const
{
    if (ptr_to_word == nullptr)
    {
        std::cout << "There are no added words yet!\n";
    }
    else
    {
        std::cout << ptr_to_word << '\n';
    }
}

void REPL::print_save_result() const
{
    std::cout << "Successfully saved!\n";
}

void REPL::print_open_result() const
{
    std::cout << "Successfully opened!\n";
}

void REPL::print_help() const
{
    std::cout << "Commands:\n";
    std::cout << "1. [add <word>] - adds <word> to the list\n";
    std::cout << "2. [get-word] - prints a random word from the list\n";
    std::cout << "3. [open] - add the words from a file to the current list\n";
    std::cout << "4. [save] - saves the current list of words\n";
    std::cout << "5. [exit] - the program terminates after saving the current words\n";
    std::cout << "6. [help] - prints this message\n";
}
