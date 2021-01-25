#include "CoinSpawner.hpp"


CoinSpawner::CoinSpawner()
{
    _spawn_delay = Utilities::randInt(1, 3);
    _coins.clear();
}

CoinSpawner::~CoinSpawner()
{
    
}


std::list<Coin> &CoinSpawner::getCoins()
{
    return _coins;
}

void CoinSpawner::update(double dt)
{
    _elapsed += dt;

    // spawn coin if conditions are met
    if((_elapsed > _spawn_delay) && _coins.size() < 20)
    {
        _elapsed = 0;
        _spawn_delay = Utilities::randInt(1, 3);
        _coins.push_back({});
    }

    // update all coins in list
    for(auto it = _coins.begin(); it != _coins.end(); it++)
    {
        it->update(dt);
    }
}