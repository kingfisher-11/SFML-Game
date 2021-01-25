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

    enum {spawning, idle} _state;

    double _elapsed = 0.0;

    const u_int _max_radius = 16;
    const u_int _min_radius = 10;

    void spawnAnimation(double);
public:

    Coin();
    ~Coin();

    void update(double);
};