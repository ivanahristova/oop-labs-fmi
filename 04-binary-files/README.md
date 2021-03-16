# Двоични файлове

За работа с текстови файлове погледнете [миналото упражнение](https://github.com/IvanaHristova/oop-labs-fmi/tree/main/03-text-files).\
Това упражнение ще се фокусира върху работата с двоични файлове.

---
### [Задачи упражнение №4](#задачи)
---

## Работа с двоични файлове
Нека имаме следната структура, описваща кола от F1:
```cpp
const int MAX_SIZE = 65;

struct F1Car
{
    char team_name[MAX_SIZE];
    char car_name[MAX_SIZE];
    double top_speed; // km/h
    bool has_won;
};
```
и сме инициализирали една кола:
```cpp
F1Car car;
strcpy(car.team_name, "Red Bull");
strcpy(car.car_name, "RB16B");
car.top_speed = 350;
car.has_won = false;
```
Ще я използваме за следващите примери.

### Писане във файл
```cpp
std::ofstream o_file("files/rb-car.bin", std::ios::binary);

if (!o_file.is_open())
{
    // handle error
}

int length = strlen(car.team_name);
o_file.write((char*)&length, sizeof(int));
o_file.write((char*)&car.team_name, length);

length = strlen(car.car_name);
o_file.write((char*)&length, sizeof(int));
o_file.write((char*)&car.car_name, length);

o_file.write((char*)&car.top_speed, sizeof(double));
o_file.write((char*)&car.has_won, sizeof(bool));

o_file.close();
```

### Четене от файл
```cpp
std::ifstream i_file("files/rb-car.bin", std::ios::binary);

if (!i_file.is_open())
{
    // handle error
}

F1Car car;

int length;
i_file.read((char*)&length, sizeof(int));
i_file.read(car.team_name, length);
car.team_name[length] = '\0';

i_file.read((char*)&length, sizeof(int));
i_file.read(car.car_name, length);
car.car_name[length] = '\0';

i_file.read((char*)&car.top_speed, sizeof(double));
i_file.read((char*)&car.has_won, sizeof(bool));

i_file.close();
```

## Задачи
1. Ще получите [двоичен файл](files/array.bin), който съдържа най-много 10 000 цели числа. Сортирайте ги в нарастващ ред и запишете сортирания масив във файла.

2. Направете система за работа с книгите в личната Ви библиотека.
Всяка книга има заглавие, автор, година на издаване и брой страници.
Системата Ви трябва да има следните функционалности:
    * Записване на книгите в двоичен файл
    * Зареждане на информация за книгите от двоичен файл
    * Добавяне на книга към библиотеката
    * Извеждане на статистика от вида: *автор - брой книги*
    * Търсене на книга по заглавие и автор
