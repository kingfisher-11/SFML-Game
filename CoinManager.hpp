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
    const Zone &_zone;
    std::list<Coin> _coins = {};

    void spawnCoin();
    void updateCoins(double dt);
public:

    CoinManager(Zone &zone, Player &player);
    ~CoinManager();

    void update(double dt);
    std::list<Coin> &getCoins();
};