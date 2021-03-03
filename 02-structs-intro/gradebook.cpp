#include <iostream>
#include <cstring>

const int default_max_len = 256;
const int max_grades_count = 100;

struct Gradebook
{
    char student_name[default_max_len];
    int faculty_number;
    int grades_count;
    double grades[max_grades_count];
    char subject_names[max_grades_count][default_max_len];
};

bool add_grade(Gradebook& gradebook, const double grade, const char subject_name[])
{
    const double min_grade = 2;
    const double max_grade = 6;
    if (grade < min_grade || grade > max_grade || gradebook.grades_count >= max_grades_count)
    {
        return false;
    }

    bool existed = false;
    for (int i = 0; i < gradebook.grades_count && !existed; i++)
    {
        if (strcmp(gradebook.subject_names[i], subject_name) == 0)
        {
            gradebook.grades[i] = grade;
            existed = true;
        }
    }

    if (existed)
    {
        return true;
    }

    strcpy(gradebook.subject_names[gradebook.grades_count], subject_name);
    gradebook.grades[gradebook.grades_count] = grade;

    gradebook.grades_count++;

    return true;
}

void swap(double* a, double* b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(char a[default_max_len], char b[default_max_len])
{
    // store one string temporarily
    char tmp[default_max_len];
    strcpy(tmp, a);

    strcpy(a, b);
    strcpy(b, tmp);
}

void sort_grades(Gradebook& gradebook)
{
    for (int i = 0; i < gradebook.grades_count - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < gradebook.grades_count; j++)
        {
            if (gradebook.grades[j] < gradebook.grades[min_index])
            {
                min_index = j;
            }
        }

        swap(&gradebook.grades[i], &gradebook.grades[min_index]);
        swap(gradebook.subject_names[i], gradebook.subject_names[min_index]);
    }
}

double get_gpa(const Gradebook& gradebook, int& failed_count, bool ignore_failed = true)
{
    const double min_passing_grade = 3;
    double grades_sum = 0;
    failed_count = 0;

    for (int i = 0; i < gradebook.grades_count; i++)
    {
        if (gradebook.grades[i] < min_passing_grade)
        {
            failed_count++;

            if (ignore_failed)
            {
                continue;
            }
        }

        grades_sum += gradebook.grades[i];
    }

    if (ignore_failed)
    {
        return grades_sum / (gradebook.grades_count - failed_count);
    }
    else
    {
        return grades_sum / gradebook.grades_count;
    }
}

void print_grades(const Gradebook& gradebook)
{
    for (int i = 0; i < gradebook.grades_count; i++)
    {
        std::cout << gradebook.grades[i] << " " << gradebook.subject_names[i] << "\n";
    }
}

bool can_advance(const Gradebook& gradebook)
{
    const double min_gpa_to_pass = 4;
    const int max_failed_count = 4;
    int failed_count = 0;
    double avg = get_gpa(gradebook, failed_count);

    if (failed_count > max_failed_count)
    {
        return false;
    }
    if (failed_count < max_failed_count)
    {
        return true;
    }

    return avg >= min_gpa_to_pass;
}

bool can_get_scholarship(const Gradebook& gradebook)
{
    const double min_gpa = 5.5;

    int failed_subjects_count = 0;
    double gpa = get_gpa(gradebook, failed_subjects_count);

    return gpa >= min_gpa && failed_subjects_count < 1;
}

int main()
{
    // memory is allocated now - when defining an object
    Gradebook john_gradebook;
    strcpy(john_gradebook.student_name, "John");
    john_gradebook.faculty_number = 83003;
    john_gradebook.grades_count = 0;

    // add some grades
    add_grade(john_gradebook, 6, "Algebra");
    add_grade(john_gradebook, 4, "Calc");
    add_grade(john_gradebook, 5, "Programming");
    add_grade(john_gradebook, 2, "Very Hard Subject");
    add_grade(john_gradebook, 1, "Invalid");

    // check gpa and failed exams
    int failed_count = 0;
    std::cout << get_gpa(john_gradebook, failed_count) << "\n";
    std::cout << get_gpa(john_gradebook, failed_count, false) << "\n";

    std::cout << "Failed exams: " << failed_count << "\n\n";

    // sort grades
    print_grades(john_gradebook);

    std::cout << "\nSorting grades...\n\n";
    sort_grades(john_gradebook);

    print_grades(john_gradebook);
    std::cout << "Can advance: " << can_advance(john_gradebook) << "\n\n";

    add_grade(john_gradebook, 2.8, "Another hard one");
    add_grade(john_gradebook, 2.9, "Tough subject");
    add_grade(john_gradebook, 2.2, "Failed subject");

    sort_grades(john_gradebook);
    print_grades(john_gradebook);
    std::cout << "GPA from non-failed: " << get_gpa(john_gradebook, failed_count)
            << ", can advance: " << can_advance(john_gradebook) << "\n";

    add_grade(john_gradebook, 2.2, "Failed another one");
    std::cout << "\nCan advance with 5: " << can_advance(john_gradebook) << "\n";


    Gradebook jane_gradebook;
    strcpy(jane_gradebook.student_name, "Jane");
    jane_gradebook.faculty_number = 83005;
    jane_gradebook.grades_count = 0;

    add_grade(jane_gradebook, 6, "Algebra");
    add_grade(jane_gradebook, 5, "Calc");

    std::cout << "\nJane can get scholarship: " << can_get_scholarship(jane_gradebook) << "\n";
}
