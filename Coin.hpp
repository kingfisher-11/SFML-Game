#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

#include "Zone.hpp"
#include "Utilities.hpp"



class Coin : public sf::CircleShape
{
private:

    enum {spawning, idle, vanishing, vanished} _state;

    double _elapsed = 0.0;

    Zone *_zone;

    const u_int _max_radius = 20;
    const u_int _min_radius = 14;
public:

    Coin(Zone&);
    ~Coin();

    void update(double);
    void setVanishing();
    bool isVanished();
};