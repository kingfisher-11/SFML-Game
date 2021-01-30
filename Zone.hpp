#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>


class Zone : public sf::CircleShape
{
private:

    enum {shrinking, expanding} _state;

    double _max_radius = 2000;
    double _elapsed = 0;
public:

    Zone();
    ~Zone();

    void update(double);
};

