#include "CoinManager.hpp"


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

void CoinSpawner::update(Zone &zone, Player &player, double dt)
{
    _elapsed += dt;

    // spawn coin if conditions are met
    if((_elapsed > _spawn_delay) && _coins.size() < 40)
    {
        _elapsed = 0;
        _spawn_delay = ut::randDouble(1.5, 2.0);

        uint player_dist_from_origin = ut::distance2V({0, 0}, player.getPosition());
        uint angle = ut::randInt(0, 360);
        uint distance_from_origin = 0;

        // coin position is recalculated until it is at least 20px away from player
        // TODO: use to make coins spawn away from each other (maybe)
        while(true)
        {
            // this is to prevent the loop from freezing the game when coins can't spawn
            if(zone.getRadius() < 200 + player.getRadius() * 2)
                break;

            distance_from_origin = ut::randInt(0, std::max(zone.getRadius() - 100, 0.f));

            if(abs(player_dist_from_origin - distance_from_origin) < player.getRadius() * 2)
                continue;

            sf::Vector2f coin_position = {distance_from_origin * sin(angle), distance_from_origin * cos(angle)};

            _coins.push_back({zone, coin_position});

            break;
        }
    }

    // updates all coins
    for(auto &it : _coins)
        it.update(dt);
}