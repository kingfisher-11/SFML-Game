#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>

#include "Zone.hpp"
#include "Utilities.hpp"



class Coin : public sf::CircleShape
{
private:

    const u_int _max_radius = 16;
    const u_int _min_radius = 10;

    void spawnAnimation();
public:

    Coin();
    ~Coin();

    void update(double);
};