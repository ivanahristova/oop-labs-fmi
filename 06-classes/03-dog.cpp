#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>

const int MAX_LEN = 100;
const int MAX_AGE_IN_MONTHS = 720;
const int DOGS_CAPACITY = 15;

class Dog
{
private:
    char name[MAX_LEN];
    int age_in_months;
    bool female;

public:
    Dog(const char* name = "Rex");
    Dog(const char* name, int age_in_months, bool is_female);

    const char* get_name();
    int get_age_in_months();
    bool is_female();

    void set_name(const char* new_name);
    void grow_older();

    int get_age_in_human_years();
    void print();
};

Dog::Dog(const char* name) : age_in_months(0), female(false)
{
    set_name(name);
}

Dog::Dog(const char* name, int age_in_months, bool female) : female(female)
{
    assert(age_in_months >= 0 && age_in_months < MAX_AGE_IN_MONTHS);

    this->age_in_months = age_in_months;
    set_name(name);
}

const char* Dog::get_name()
{
    return name;
}

int Dog::get_age_in_months()
{
    return age_in_months;
}

bool Dog::is_female()
{
    return female;
}

void Dog::set_name(const char* new_name)
{
    assert(strlen(new_name) < MAX_LEN);
    strcpy(name, new_name);
}

void Dog::grow_older()
{
    assert(age_in_months + 1 <= MAX_AGE_IN_MONTHS);
    age_in_months++;
}

int Dog::get_age_in_human_years()
{
    // this function returns negative age for 0 and 1 month-olds, so we take them out
    if (age_in_months == 0)
    {
        return 0;
    }
    if (age_in_months == 1)
    {
        return 1;
    }

    return 16 * log(age_in_months / 12.0) + 31;
}

void Dog::print()
{
    std::cout << name << ", " << age_in_months << " mo, " << (female ? "female" : "male") << "\n";
}

class DogShelter
{
private:
    Dog dogs[DOGS_CAPACITY];
    int dogs_count = 0;     // since C++11

public:
    void print_dog_list();
    bool has_space();
    void add_dog(const Dog& dog);
    Dog release_dog(int index);
};

void DogShelter::print_dog_list()
{
    if (dogs_count < 1)
    {
        std::cout << "Shelter is empty\n";
        return;
    }

    for (int i = 0; i < dogs_count; i++)
    {
        std::cout << i << ". ";
        dogs[i].print();
    }
}

bool DogShelter::has_space()
{
    return dogs_count + 1 < DOGS_CAPACITY;
}

void DogShelter::add_dog(const Dog& dog)
{
    assert(has_space());

    dogs[dogs_count++] = dog;
}

Dog DogShelter::release_dog(int index)
{
    assert(index >= 0 && index < dogs_count);

    Dog to_be_released = dogs[index];

    for (int i = index + 1; i < dogs_count; i++)
    {
        dogs[i - 1] = dogs[i];
    }

    dogs_count--;
    return to_be_released;
}

int main()
{
    Dog rex;
    Dog benji("Benji", 15, false);

    std::cout << benji.get_age_in_human_years() << "\n";

    DogShelter shelter;
    shelter.add_dog(benji);
    shelter.add_dog(rex);

    std::cout << "\nAll dogs:\n";
    shelter.print_dog_list();
    std::cout << "\n";

    std::cout << "Has space: " << std::boolalpha << shelter.has_space() << "\n";
    shelter.release_dog(1);

    std::cout << "\nAll dogs:\n";
    shelter.print_dog_list();
}
