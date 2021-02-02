#pragma once

#include "SFML/Graphics.hpp"
#include "Utilities.hpp"

#include <iostream>
#include <cmath>


class ZoneParticle : public sf::RectangleShape
{
private:

    double _lifespan;
    double _elapsed = 0.0;
    bool _expired = false;

    sf::Vector2f _velocity;
public:

    ZoneParticle(sf::Vector2f position);
    ~ZoneParticle();

    void update(double dt);
    bool &expired();
};