#pragma once

#include "SFML/System.hpp"
#include <list>
#include <cmath>
#include <iostream>

#include "Coin.hpp"
#include "Utilities.hpp"
#include "Player.hpp"


class CoinSpawner
{
private:

    double _elapsed;
    int _spawn_delay;
    std::list<Coin> _coins = {};
public:

    CoinSpawner();
    ~CoinSpawner();

    std::list<Coin> &getCoins();
    void update(Zone& zone, Player& player, double dt);
};