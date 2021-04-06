#include "helper-functions.h"
#include <cstring>
#include <cstdlib>
#include <time.h>

int get_random_number(int upper_bound)
{
    srand((unsigned)time(0));
    return rand() % upper_bound;
}

void get_argument(const char* command, char* current)
{
    int index = 0;
    int upper_bound = strlen(command);
    while(index < upper_bound && command[index] != ' ')
    {
        current[index] = command[index];
        index++;
    }
    current[index] = '\0';
}
