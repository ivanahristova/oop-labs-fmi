#ifndef COIN_H
#define COIN_H

enum class Coin {One, Two, Five, Ten, Twenty, Fifty, Lev, TwoLeva};
int operator*(Coin coin);

#endif
