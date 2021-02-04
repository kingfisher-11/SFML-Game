#pragma once

#include "SFML/System.hpp"
#include <random>
#include <cmath>
#include <iostream>


namespace ut
{
    int randInt(const int lower_bound, const int upper_bound);
    double randDouble(const double lower_bound, const double upper_bound);

    double distance2V(sf::Vector2f point1, sf::Vector2f point2);
    double degrees2V(sf::Vector2f point1, sf::Vector2f point2);
}
