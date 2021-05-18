# Полиморфизъм

## Въведение

*поли* - много</br>
*морфо* - форми 

**`virtual`**: декларирането на метод като виртуален позволява той да бъде предефиниран в производните класове. 

Правила:
1. Виртуалните функции не могат да бъдат статични.
2. Прототипът на виртуален метод трябва да бъде един и същи в базовия и наследения клас.
3. Виртуалните методи се дефинират в базовия клас. В производните класове те се предефинират, ако
   е нужно. Ако метод не е предефиниран в класа-наследник се използва базовата му дефиниция.
4. Клас може да има виртуален деструктор, но не и виртуален конструктор.

## Пример
```cpp
class Customer 
{
protected:
    double membership_fee;
public:
    Customer() : membership_fee(20) {}
    double get_membership_fee() { return membership_fee; }
};

class PremiumCustomer : public Customer
{
public:
    PremiumCustomer() : Customer() {}
    double get_membership_fee() { return membership_fee / 2; }
};

int main()
{
    Customer* c1 = new Customer();
    Customer* p1 = new PremiumCustomer();
    std::cout << c1->get_membership_fee() << '\n';      // What will it print?
    std::cout << p1->get_membership_fee() << '\n';      // What will it print?
}
```

```cpp
class Customer 
{
    double membership_fee;
public:
    Customer() : membership_fee(20) {}
    virtual double get_membership_fee() { return membership_fee; }
};

class PremiumCustomer : public Customer
{
public:
    PremiumCustomer() : Customer() {}
    double get_membership_fee() override { return membership_fee / 2; }
};

int main()
{
    Customer* c1 = new Customer();
    Customer* p1 = new PremiumCustomer();
    std::cout << c1->get_membership_fee() << '\n';      // What will it print?
    std::cout << p1->get_membership_fee() << '\n';      // What will it print?
}
```

## Типове полиморфизъм

| Compile time polymorphism | Runtime polymorphism |
| --- | --- |
| Също се нарича **статично свързване** | Също се нарича **динамично свързване** |
| Чрез *function overloading* и *operator overloading* | Чрез *method overriding* |
| Осъществява се по време на **компилация** | Осъществява се по време на **изпълнение** |
| **Няма** отражение въхру производителността | **Има** отражение върху производителността |

&nbsp;

:question: Кой тип според вас дава по-големи възможности?

:exclamation: *overloading* vs *overriding*:
- *overloading* – позволява да съществува функция с едно и също име,
  но различен брой и/или тип параметри.
- *overriding* – предефиниране на метод в производен клас. Има същата сигнатура
  като метода на базовия клас - същия тип на връщане и параметри.

## Абстрактен клас
Клас, който има поне една чисто виртуална (*pure virtual*) член-функция. Чисто виртуален метод е такъв без дефиниция в базовия клас.</br>
Декларация:
```cpp 
virtual <return type> method(<parameters>) = 0;
```

Дефиниция за чисто виртуалните методи трябва да се даде в производния клас. В противен случай производният клас също ще бъде абстрактен. 

:exclamation: Не могат да се създават обекти от абстрактен клас.

## Задачи

1. Създайте опростен калкулатор, при който:
- Всяка константа е израз.
- Всичко от вида -(израз) е израз.
- Всичко от вида (израз)^(константа) е израз.
- Всичко от вида (израз + израз) е израз.
- Всичко от вида (израз * израз) е израз.

Трябва да има метод evaluate(), който позволява да се намери стойността на подаден израз.

2. Създайте система за склад. В склада има информация за всички продукти, които има в него. Продуктите са различни типове - химикалка, тетрадка..., но всеки от тях има цена и количество. Склада трябва да поддържа следните функционалности:
- намиране на общата цена на всички продукти
- добавяне на количество от даден продукт
- продаване на количество от даден продукт
