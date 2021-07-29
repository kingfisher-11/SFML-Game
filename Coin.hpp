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

    uint _rotation_speed;
    double _elapsed = 0.0;

    const Zone &_zone;

    const u_int _max_radius = 20;
    const u_int _min_radius = 14;
    
public:

    Coin(const Zone &zone, sf::Vector2f position);
    ~Coin();

    void update(double dt);
    void setVanishing();
    bool isVanished() const;
    bool isVanishing() const;
};