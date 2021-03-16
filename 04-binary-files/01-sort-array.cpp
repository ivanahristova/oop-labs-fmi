#include <iostream>
#include <fstream>

// Функция, която съединява двата подмасива
void merge(int arr1[], int size1, int arr2[], int size2)
{
    int size = size1 + size2; // Обща дължина на подмасивите
    int* result = new int[size1 + size2]; // Временен масив, в който пазим подредбата на елементите на arr1 и arr2
    int cursor1 = 0; // Курсор, с който ще се движим в първия подмасив
    int cursor2 = 0; // Курсор, с който ще се движим във втория подмасив
    int result_cursor = 0; // Курсор, с който ще се движим в общия масив

    // Цикълът приключва когато поне един от масивите достигне края си
    while (cursor1 < size1 && cursor2 < size2)
    {
        // Ако елементът от първия масив е по-малък или равен, записваме първо него в резултата
        // Помислете: Защо ни е равенство в сравнението, какво ни дава?
        if (arr1[cursor1] <= arr2[cursor2])
        {
            result[result_cursor++] = arr1[cursor1++];
        }
        else
        {
            result[result_cursor++] = arr2[cursor2++];
        }
    }

    // Ако вторият подмасив е стигнал края си първи, то сме сигурни, че всички останали елементи от
    // първия подмасив са по-големи (понеже той е сортиран във възходящщ ред)
    while (cursor1 < size1)
    {
        result[result_cursor++] = arr1[cursor1++];
    }
    // Ако първият подмасив е стигнал края си първи => аналогично на горния цикъл
    while (cursor2 < size2)
    {
        result[result_cursor++] = arr2[cursor2++];
    }

    // Трябва да запишем новополучения подреден масив на място в паметта, което имаме.
    // Понеже result масива е бил заделен в тази функция, то неговата памет ще се освободи
    // при излизането от нея.
    for (int i = 0; i < size; i++)
    {
        arr1[i] = result[i];
    }

    delete[] result; // Освобождаваме паметта на result, за да не се получи memory leak
}

// Каква е сложността на алгоритъма?
void merge_sort(int* arr, int size)
{
    // Дъно: масив от един елемент е винаги сортиран
    if (size <= 1)
    {
        return;
    }

    int mid = size / 2; // Индекс за средата на масива
    merge_sort(arr, mid); // Сортираме лявата му половина (левия подмасив)
    merge_sort(arr+mid, size - mid); // Сортираме дясната половина
    merge(arr, mid, arr + mid, size - mid); // Слепваме двете сортирани части
}

void read_file(int arr[], int& size)
{
    std::ifstream i_file("files/array.bin", std::ios::binary);

    if (!i_file)
    {
        return;
    }

    int cursor = 0;
    while(!i_file.eof()) // +1 заради eofbit
    {
        i_file.read((char*)&arr[cursor++], sizeof(int));
    }

    cursor--;
    size = cursor;
    i_file.close();
}

int main()
{
    const int max_size = 10000;
    int arr[max_size];
    int actual_size = 0;
    read_file(arr, actual_size);
    merge_sort(arr, actual_size);

    for (int i = 0; i < actual_size; i++)
    {
        std::cout << arr[i] << ' ';
    }


    return 0;
}
