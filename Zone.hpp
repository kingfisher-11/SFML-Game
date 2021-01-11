#pragma once

#include "SFML/Graphics.hpp"


class Zone : public sf::CircleShape
{
private:

    // zone properties
    const double _zone_radius = 500.0;
public:

    Zone();
    ~Zone();

    void update(double);
};

