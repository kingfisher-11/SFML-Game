#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>

#include "ZoneParticle.hpp"
#include "Utilities.hpp"


class Zone : public sf::CircleShape
{
private:

    enum {shrinking, expanding} _state;

    static constexpr double _max_radius = 2000;
    double _elapsed = 0;

    std::list<ZoneParticle> _particles;
public:

    Zone(double radius = _max_radius);
    ~Zone();

    void update(double);
    const std::list<ZoneParticle> &getParticles();
};

