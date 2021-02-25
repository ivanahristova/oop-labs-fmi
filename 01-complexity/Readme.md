# Сложност
```
Скоростта на нарастването на времето и паметта, необходими за изпълнението на даден алгоритъм, с нарастването на входните данни.
```
> Ще означаваме размера на входните данни с **n**.

* ## Нотации
    * #### <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O"> **(Big-O) notation**:
        * <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O(f)"> - множеството от всички функции, които растат **не** по-бързо от <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}f"> \
    <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O(f)=\{g\ |\ g \preceq f\}"> \
    e.g. <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O(n^2)=\{n^2,n,1,\log n, \ldots\}"> 
    * #### <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}\Omega"> **(Big-Omega) notation**:
        * <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}\Omega(f)"> - множеството от всички функции, които растат **не** по-бавно от <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}f"> \
        <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}\Omega(f)=\{g\ |\ g \succeq f\}">
    * #### <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}\Theta"> **(Theta) notation**:
        * <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}\Theta(f)"> - множеството от всички функции, които растат със скоростта на <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}f"> \
        <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}\Theta(f)=\{g\ |\ g \simeq f\}">

:round_pushpin:
<img src="https://render.githubusercontent.com/render/math?math=\color{orangered}\forall \! \! f\ \ \ O(f) \cap \Omega(f) = \Theta(f)">

* ## Неформални правила
1. Адитивните константи се игнорират
2. Мултипликативните константи се игнорират
3. Сложността на един алгоритъм отговаря на тази функция, която расте "най-бързо" ("най-тежката" функция)

* ## Често срещани функции
  1. Константна 
        * Практически най-добрата сложност
        * Не зависи от обема на входните данни
        * <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O(1)">
  2. Логаритмична
        * <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O(\log(n))">
        * Двоично търсене, алгоритъм на Евклид
  3. Линейна
        * <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O(n)">
        * Среща се в алгоритми, които обработват всеки обект
  4. Квадратична
        * <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O(n^2)">
  5. Кубична
        * <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O(n^3)">
  6. Експоненциална
        * <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O(2^n)">
        * <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O(n!)">
        *  <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O(n^n)">
        * <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}O(2^{n^2})">

:warning:\
<img src="https://render.githubusercontent.com/render/math?math=\color{orangered}\log(n) \prec \sqrt{n} \prec n \prec n \log n \prec n^2 \prec 2^n">\
<img src="https://render.githubusercontent.com/render/math?math=\color{orangered}n^0.3 \prec \sqrt{n} \prec n \prec n \log n \prec n^2 \prec 5^{\log(n)} \prec 3^n \prec 2^{2^n}">

* ## Сложност по време
> Как расте времето за изпълнение при нарастване на входа?

* ## Сложност по памет
> Как расте необходимата памет при нарастване на входа?

* ## 

| n | 10 | 100 | 1 000 | 100 000 | 1 000 000 | 100 000 000 |
| --- | --- | --- | --- | --- | --- | --- |
| <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}const = 5"> | 5 | 5 | 5 | 5 | 5 | 5 |
| <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}\log(n)"> | 3 | 6 | 9 | 16 | 19 | 26 |
| <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}n"> | 1 | 100 | 1 000 | 100 000 | 1 000 000 | 100 000 000 |
| <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}n \log(n)"> | 33 | 664 | 9 966 | 1 660 964 | 19 931 568 | 2 657 542 475 |
| <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}n^2"> | 100 | 10 000 | 1 000 000 | 10 000 000 000 | 1 000 000 000 000 | <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}10^16"> |
| <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}n^3">| 1 000 | 1 000 000 | 1 000 000 000 | <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}10^15"> | <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}10^18"> | <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}10^24"> |
| <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}2^n"> | 1 024 | <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}10^30"> | <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}10^300"> | :turtle: | :turtle: | :turtle: |
| <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}\!\!n!"> | 3 628 800 | <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}10^157"> | <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}10^2567"> | :snail: | :snail: | :snail: |
| <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}n^n"> | 10 000 000 000 | <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}10^200"> | <img src="https://render.githubusercontent.com/render/math?math=\color{orangered}10^3000"> | :skull: | :skull: | :skull: |

&nbsp;
* ## Основни моменти при разглеждане на алгоритми
1. Простота
2. Коректност
3. Бързодействие