#include "CoinManager.hpp"


CoinManager::CoinManager(Zone &zone, Player &player)
:_zone(zone), _player(player)
{

}

CoinManager::~CoinManager()
{
    
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

            sf::Vector2f coin_position = {distance_from_origin * sin(angle), distance_from_origin * cos(angle)};

            _coins.push_back({_zone, coin_position});

            break;
        }
    }

    // updates all coins
    for(auto &it : _coins)
        it.update(dt);
}

std::list<Coin> &CoinManager::getCoins()
{
    return _coins;
}