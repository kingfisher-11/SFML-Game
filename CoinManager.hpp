#pragma once

#include "SFML/System.hpp"
#include <list>
#include <cmath>
#include <iostream>

#include "Coin.hpp"
#include "Utilities.hpp"
#include "Player.hpp"


class CoinManager
{
private:

    Player &_player;
    Zone &_zone;
    std::list<Coin> _coins = {};
public:

    CoinManager(Zone &zone, Player &player);
    ~CoinManager();

    void update(double dt);
    std::list<Coin> &getCoins();
};