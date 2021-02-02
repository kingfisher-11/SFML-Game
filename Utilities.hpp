#pragma once

#include "SFML/System.hpp"
#include <random>
#include <cmath>


namespace ut
{
    int randInt(const int lower_bound, const int upper_bound);
    double randDouble(const double lower_bound, const double upper_bound);
    double distance2V(sf::Vector2f, sf::Vector2f);
}
