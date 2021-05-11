# Наследяване

[Към задача](#задача)

В коя секция 'отиват' член данните на базовия клас при наследяване:
| Видимост в базовия клас | Видимост при `public` наследяване в производния клас | Видимост при `protected`  наследяване в производния клас | Видимост при `private`  наследяване в производния клас |
|-------------------------|------------------------------------------------------|----------------------------------------------------------|--------------------------------------------------------|
| `public`                | `public`                                             | `protected`                                              | `private`                                              |
| `protected`             | `protected`                                          | `protected`                                              | `private`                                              |
| `private`               | няма достъп                                          | няма достъп                                              | няма достъп                                            |

&nbsp;

## Задача

Майстор Чани е замислил нов проект с кола, но се нуждае от части.

**(a)** Създайте клас `CarPart`, описващ част за кола.

Всяка част за кола има:
- идентификатор;
- име на производител;
- описание.

Всички са низове с произволна дължина.

**(б)** Майсторът в момента главно се интересува от двигатели, гуми и акумулатори.

Гумите имат:
- широчина в мм – между 155 и 365;
- профил – между 30 и 80;
- диаметър в инчове – между 13 и 21.

Двигателите се характеризират с **конски сили**.

Акумулаторите имат:
- капацитет – в ампер-часове;
- battery id – идентификатор, независим от този за всяка част (низ с произволна дължина)

Реализирайте подходящи класове за различните части.

Създайте и подходящи оператори `<<`, които да извеждат информация за част в следния формат:
- за двигател:
```
(<id>) by <manufacturer> – <description> – <horsepower> hp
```
- за гума:
```
(<id>) by <manufacturer> – <description> – <width>/<profile>R<rim size>
```
- за акумулатор:
```
(<id>) by <manufacturer> – <description> – <amp hours> Ah
```

Създайте операторите с минимална дупликация на код.

[Подсказка 1](#подсказка-1)

**(в)** Почти сме готови да си сглобим кола, но се нуждаем от място,
където ще държим горивото.

Направете подходящ клас `FuelTank` за целта.

Един резервоар има капацитет и пълнота към момента. И двете стойности се измерват в литри и са реални числа.

Създайкте конструктор, приемащ капацитет на резервоара.
Всеки нов резервоар първоначално е пълен.

Създайте методи:
- за използване на дадено количество гориво:
  ```cpp
  void FuelTank::use(double to_use);
  ```

- за зареждане на дадено количество гориво:
  ```cpp
  void FuelTank::fill(double to_fill);
  ```

При зареждане на прекалено много гориво, резервоарът остава пълен.

При опит за използване на количество гориво, повече от наличното,
да се хвърля custom изключение `insufficient_fuel_error`.

Изключението трябва да е пряк наследник на `std::logic_error`
и да може да се създава такова с единствен параметър – съобщение, описващо грешката.

Използвайте някой конструктор на `std::logic_error`, за да изградите този на `insufficient_fuel_error`.

**(г)** Реализирайте клас `Car`, използвайки частите, които създадохте.

Една кола има поне:
- резервоар;
- двигател;
- 4 гуми;
- акумулатор;
- изминати километри;
- тегло (в кг).

[Подсказка 2](#подсказка-2)

Създайте конструктор за кола, приемаща всички нужни член данни, както и капацитет на резервоара.

Създайте get-ър за резервоара:
```cpp
const FuelTank& get_fuel_tank();
```

Създайте член-функция `drive(double km)`.
Резултатът от изпълнението на функцията е:
- добавя се дистанцията към изминатите километри;
- намалява се количеството гориво в резервоара с произведението на `km` и изразходваното гориво на 1 км;
горивото, използвано за 1 км се смята по следната формула:
![Формула за използвано гориво на 1 км](../img/11-01-fuel-per-km-formula.png)

Ако колата няма достатъчно гориво, не се променя състоянието ѝ по никакъв начин.

[Подсказка 3](#подсказка-3)

Създайте външна за класа функция за драг състезание между две коли:
```cpp
Car* drag_race(Car* car1, Car* car2);
```

To се случва на разстояние 0.4 km (1/4 mile).
Функцията трябва да връща `Car*`, сочейки към евентуалния победител от него.

Ако една от колите няма достатъчно гориво, за да измине разстоянието, другата печели.

Ако и двете коли **нямат** достатъчно гориво, да се върне `nullptr`.

Ако и двете коли **имат** достатъчно гориво, победителят се определя от съотношението:

![Съотношение 'мощност'–'тегло'](../img/11-02-power-to-weight-ratio.png)

Колата с по-високо съотношение печели.

[Подсказка 4](#подсказка-4)

### Подсказки

#### **Подсказка 1**
<details>
  <summary>Виж</summary>

  Създайте `operator <<` за базовия клас и го преизползвайте в производния.

  За да се извика операторът за базовия клас от производния, трябва производният да бъде cast-нат до базовия.

  Например, за `Engine` може да го извикате по някой от тези начини:

  ```cpp
  operator<<(o_stream, (CarPart&) engine);
  ```
  ```cpp
  o_stream << (CarPart&)engine;
  ```

След това просто извеждате допълнителната информация за производния клас (пр. конски сили за двигателя).

</details>

#### **Подсказка 2**
<details>
  <summary>Виж</summary>

  За член-данните двигател, четири гуми и акумулатор може да използвате следните член данни:
  - `Engine*`;
  - `Tyre*[4]`;
  - `Battery*`;

  Това значи, че, например, един двигател може да се използва за множество коли,
  но не винаги целта е кодът да е огледало на реалния свят – интересуваме се повече от
  поведението на обектите. В случая `Engine`, `Tyre` и `Battery` нямат никакво поведение,
  затова си позволяваме да не правим копия от тях.

  Не пречи и да държите копия в `Car`, т.е. `Engine`, `Tyre[4]` и `Battery`,
  само ще се нуждаете от default-ен конструктор за `Tyre`,
  тъй като приемаме масив от такъв тип.

  За `FuelTank` – вече би било грешка няколко обекти от тип `Car`
  да споделят един резервоар.

</details>

#### **Подсказка 3**
<details>
  <summary>Виж</summary>

  Може да използвате функцията `log` от `<cmath>`, която връща
  натурален логаритъм от дадено число, и следното свойство:

  ![Свойство на логаритмите за смяна на основата](../img/11-03-log-property-base-change.png)

</details>

#### **Подсказка 4**
<details>
  <summary>Виж</summary>

  Mоже да използвате `try/catch` клаузите върху метода `drive` на колите и да хващате
  изключението `insufficient_fuel_error`, за да постигнете исканото.

  Ако се нуждаете от непублични член данни на
  колите, може да декларирате функцията като приятелска.

</details>