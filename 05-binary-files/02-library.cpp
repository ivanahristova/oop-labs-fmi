#include <iostream>
#include <cstring>
#include <fstream>

/*
Направете система за работа с книгите в личната Ви библиотека.
Всяка книга има заглавие, автор, година на издаване и брой страници.
Системата Ви трябва да има следните функционалности:

-> Записване на книгите в двоичен файл
-> Зареждане на информация за книгите от двоичен файл
-> Добавяне на книга към библиотеката
-> Извеждане на статистика от вида: автор - брой книги
-> Търсене на книга по заглавие и автор
*/

const int MAX_LEN = 256;

struct Book
{
    char title[MAX_LEN];
    char author[MAX_LEN];
    int year;
    int pages;

    void write_to_bin(std::ofstream& stream) const;
    void read_from_bin(std::ifstream& stream);
};

void Book::write_to_bin(std::ofstream& stream) const
{
    stream.seekp(0, std::ios::end);

    int length = strlen(title);
    stream.write((char*)&length, sizeof(int));
    stream.write(title, length);

    length = strlen(author);
    stream.write((char*)&length, sizeof(int));
    stream.write(author, length);

    stream.write((char*)&year, sizeof(int));
    stream.write((char*)&pages, sizeof(int));
}

void Book::read_from_bin(std::ifstream& stream)
{
    int length = 0;
    stream.read((char*)&length, sizeof(int));
    stream.read(title, length);
    title[length] = '\0';

    stream.read((char*)&length, sizeof(int));
    stream.read(author, length);
    author[length] = '\0';

    stream.read((char*)&year, sizeof(int));
    stream.read((char*)&pages, sizeof(int));
}

void write_books(Book* books, int size)
{
    std::ofstream o_file("files/books.bin", std::ios::binary);

    if (!o_file.is_open())
    {
        return;
    }

    for (int i = 0; i < size; i++)
    {
        books[i].write_to_bin(o_file);
    }

    o_file.close();
}

void read_books(Book* books, int& size)
{
    std::ifstream i_file("files/books.bin", std::ios::binary);

    if (!i_file.is_open())
    {
        return;
    }

    while(i_file.peek() != EOF) // .eof() -> 0/1
    {
        Book book;
        book.read_from_bin(i_file);
        books[size++] = book;
    }

    i_file.close();
}

void add_book(Book* books, int& size, const char* title, const char* author, int year, int pages)
{
    Book book;

    strcpy(book.title, title);
    strcpy(book.author, author);
    book.year = year;
    book.pages = pages;

    books[size++] = book;
}

int comparison(Book book1, Book book2) // strcmp
{
    int result_author = strcmp(book1.author, book2.author);
    if (result_author != 0)
    {
        return result_author;
    }

    return strcmp(book1.title, book2.title);
}

void merge(Book* books1, int size1, Book* books2, int size2)
{
    int size = size1 + size2;
    Book* result = new Book[size];
    int cursor1 = 0;
    int cursor2 = 0;
    int cursor_result = 0;

    while (cursor1 < size1 && cursor2 < size2)
    {
        if (comparison(books1[cursor1], books2[cursor2]) <= 0)
        {
            result[cursor_result++] = books1[cursor1++];
        }
        else
        {
            result[cursor_result++] = books2[cursor2++];
        }
    }

    while (cursor1 < size1)
    {
        result[cursor_result++] = books1[cursor1++];
    }
    while (cursor2 < size2)
    {
        result[cursor_result++] = books2[cursor2++];
    }

    for (int i = 0; i < size; i++)
    {
        books1[i] = result[i];
    }

    delete[] result;
}

void merge_sort(Book* books, int size)
{
    if (size <= 1)
    {
        return;
    }

    int mid = size / 2;
    merge_sort(books, mid);
    merge_sort(books + mid, size - mid);
    merge(books, mid, books + mid, size - mid);
}

// Изискваме масивът да е бил сортиран
void print_statistics(Book* books, int size)
{
    int counter = 1;
    for(int i = 0; i < size - 1; i++)
    {
        if (strcmp(books[i].author, books[i+1].author) == 0)
        {
            counter++;
        }
        else
        {
            std::cout << books[i].author << " - " << counter << '\n';
            counter = 1;
        }
    }

    std::cout << books[size - 1].author << " - " << counter << '\n';
}

int book_position(Book* books, int start, int end, const Book& book)
{
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;
    int comparison_result = comparison(books[mid], book);
    if (comparison_result == 0)
    {
        return mid;
    }

    if (comparison_result > 0)
    {
        return book_position(books, start, mid - 1, book);
    }
    else
    {
        return book_position(books, mid + 1, end, book);
    }
}

// Изискваме масивът да е бил сортиран
bool has_book(Book* books, int size, const char* title, const char* author)
{
    Book book;

    strcpy(book.title, title);
    strcpy(book.author, author);

    return book_position(books, 0, size - 1, book) != -1;

    /* Еквивалентно на return-a:

    // Намира индекса на елемента
    int index = book_position(books, 0, size - 1, book);

    // Ако този индекс е -1, значи елементът не е бил намерен
    if (index == -1)
    {
        return false;
    }

    return true;

    => проверката дали index != -1 е еквивалентна на описаното.
    */
}

int main()
{
    const int max_books = 1024;
    Book books[max_books];
    int actual_size = 0;

    add_book(books, actual_size, "Frankenstein", "Mary Shelley", 1818, 255);
    add_book(books, actual_size, "The Tales of Beedle the Bard", "J.K.Rowling", 2008, 104);
    add_book(books, actual_size, "1984", "George Orwell", 1949, 328);
    add_book(books, actual_size, "The Mayor of Casterbridge","Thomas Hardy", 1886, 352);
    add_book(books, actual_size, "Far from the Madding Crowd","Thomas Hardy", 1874, 429);

    write_books(books, actual_size);

    merge_sort(books, actual_size);
    std::cout << "Sorted books:\n";
    for (int i = 0; i < actual_size; i++)
    {
        std::cout << books[i].author << ' ';
        std::cout << books[i].title << ' ';
        std::cout << books[i].year << ' ';
        std::cout << books[i].pages << '\n';
    }

    std::cout << "\nStatistics:\n";
    print_statistics(books, actual_size);
    std::cout << "\nContains book \"1985\" by George Orwell: " << has_book(books, actual_size, "1985", "George Orwell");
    std::cout << "\nContains book \"1984\" by George Orwel: " << has_book(books, actual_size, "1985", "George Orwell");
    std::cout << "\nContains book \"1985\" by George Oruell: " << has_book(books, actual_size, "1985", "George Orwell");
    std::cout << "\nContains book \"1984\" by George Orwell: " << has_book(books, actual_size, "1984", "George Orwell");

    return 0;
}
