#include "CoinManager.hpp"


CoinManager::CoinManager(Zone &zone, Player &player)
:_zone(zone), _player(player)
{

}

CoinManager::~CoinManager()
{
    
}


void CoinManager::spawnCoin()
{
    uint player_dist_from_origin = ut::distance2V({0, 0}, _player.getPosition());
    uint angle = ut::randInt(0, 360);
    uint distance_from_origin = 0;

    // coin position is recalculated until it is at least 20px away from player
    // TODO: use to make coins spawn away from each other (maybe)
    while(true)
    {
        // prevent the loop from freezing the game when coins can't spawn
        if(_zone.getRadius() < 200 + _player.getRadius() * 2)
            break;

        distance_from_origin = ut::randInt(0, std::max(_zone.getRadius() - 100, 0.f));

        if(abs(player_dist_from_origin - distance_from_origin) < _player.getRadius() * 2)
            continue;

        sf::Vector2f coin_position = {distance_from_origin * (float)sin(angle), distance_from_origin * (float)cos(angle)};

        _coins.push_back({_zone, coin_position});

        break;
    }
}

void CoinManager::updateCoins(double dt)
{
    for(auto it = _coins.begin(); it != _coins.end();)
    {
        it->update(dt);

        if(it->isVanished())
        {
            it = _coins.erase(it);
        }
        else if(ut::distance2V(_player.getPosition(), it->getPosition()) <= _player.getRadius() + it->getRadius())
        {
            if(!it->isVanishing())
                _player.setScore(_player.getScore() + 1);

            it->setVanishing();
            it++;
        }
        else if(ut::distance2V({0.0, 0.0}, it->getPosition()) >= _zone.getRadius() - it->getRadius())
        {
            it->setVanishing();
            it++;
        }
        else
        {
            it++;
        }
    }
}

void CoinManager::update(double dt)
{
    static double elapsed;
    static double spawn_delay;
    elapsed += dt;

    // spawn coin if conditions are met
    if((elapsed > spawn_delay) && _coins.size() < 40)
    {
        elapsed = 0;
        spawn_delay = ut::randDouble(0.1, 0.5);
        spawnCoin();
    }

    // updates all coins
    updateCoins(dt);
}

std::list<Coin> &CoinManager::getCoins()
{
    return _coins;
}