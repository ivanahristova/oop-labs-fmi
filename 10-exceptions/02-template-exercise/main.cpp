#include "tab.h"
#include <iostream>

int main()
{
    Tab t;
    std::cout << "Default website:\n" << t.get_url() << "\n\n";

    std::cout << "Current history:\n";
    t.load("facebook.com");
    std::cout << t.get_url() << '\n';
    t.load("hackerrank.com");
    std::cout << t.get_url() << '\n';
    t.load("codewars.com");
    std::cout << t.get_url() << '\n';
    t.load("youtube.com");
    std::cout << t.get_url() << '\n';
    t.load("github.com");
    std::cout << t.get_url() << "\n\n";

    std::cout << "Current website after 3 steps back:\n";
    t.back();
    t.back();
    t.back();
    std::cout << t.get_url() << "\n\n";

    std::cout << "Current website after 1 step forward:\n";
    t.forward();
    std::cout << t.get_url() << "\n\n";

    std::cout << "Loading new website:\n";
    t.load("moodle.org");
    std::cout << t.get_url() << "\n\n";

    std::cout << "Attempting a forward move:\n";
    t.forward();

    return 0;
}