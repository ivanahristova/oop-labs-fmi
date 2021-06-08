#ifndef WORK_HPP
#define WORK_HPP

class Work
{
private:
    static const int min_rating = 1;
    static const int max_rating = 5;

    char title[200];
    int cumulative_rating;
    int ratings_given;
public:
    Work(const char* title);
    const char* get_title();
    double get_average_rating();
    void add_rating(int rating);
};

#endif // WORK_HPP
