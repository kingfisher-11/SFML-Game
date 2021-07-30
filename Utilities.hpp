#pragma once

#include "SFML/System.hpp"
#include <random>
#include <cmath>
#include <iostream>


namespace ut
{
    int randInt(int lower_bound, int upper_bound);
    float randFloat(float lower_bound, float upper_bound);
    double randDouble(double lower_bound, double upper_bound);

    double distance2V(sf::Vector2f point1, sf::Vector2f point2);
    double degrees2V(sf::Vector2f point1, sf::Vector2f point2);
}
