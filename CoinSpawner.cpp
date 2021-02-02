#include "CoinSpawner.hpp"


CoinSpawner::CoinSpawner()
{
    _spawn_delay = 0;
    _coins.clear();
}

CoinSpawner::~CoinSpawner()
{
    
}


std::list<Coin> &CoinSpawner::getCoins()
{
    return _coins;
}

void CoinSpawner::update(Zone &zone, double dt)
{
    _elapsed += dt;

    // spawn coin if conditions are met
    if((_elapsed > _spawn_delay) && _coins.size() < 40)
    {
        _elapsed = 0;
        _spawn_delay = ut::randDouble(1.5, 2.0);
        _coins.push_back({zone});
    }
}