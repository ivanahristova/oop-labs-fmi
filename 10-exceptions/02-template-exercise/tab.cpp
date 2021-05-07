#include "tab.h"

void Tab::load(const char* url) 
{
    past.push(current_url);

    current_url = url;

    future.erase();
}

void Tab::back() 
{
    future.push(current_url);

    Url prev_url;
    try 
    {
        prev_url = past.top();
    }
    catch (std::out_of_range& e)
    {
        std::cout << "There are no previous pages to go back to.\n";
        return;
    }

    current_url = prev_url;
    past.pop();

}

void Tab::forward() 
{
    past.push(current_url);

    Url next_url;
    try 
    {
        next_url = future.top();
    }
    catch (std::out_of_range& e) 
    {
        std::cout << "There are no next tabs to go forward to.\n";
        return;
    }

    current_url = next_url;
    future.pop();
}

const char* Tab::get_url() const 
{
    return current_url.get_url();
}