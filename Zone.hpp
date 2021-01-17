#pragma once

#include "SFML/Graphics.hpp"


class Zone : public sf::CircleShape
{
private:

    
public:

    // zone properties
    static constexpr double _radius = 500.0;

    Zone();
    ~Zone();

    void update(double);
};

