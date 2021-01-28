#pragma once

#include "SFML/Graphics.hpp"


class Zone : public sf::CircleShape
{
private:

    enum {shrinking, expanding} _state;

    double _max_radius = 500;
public:

    Zone();
    ~Zone();

    void update(double);
};

