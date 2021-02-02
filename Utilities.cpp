#include "Utilities.hpp"


int ut::randInt(const int lower_bound, const int upper_bound)
{
    static std::random_device rd;
    static std::mt19937 rng{rd()};

    return std::uniform_int_distribution<int>{lower_bound, upper_bound}(rng);
}

double ut::randDouble(const double lower_bound, const double upper_bound)
{
    static std::random_device rd;
    static std::mt19937 rng{rd()};

    return std::uniform_real_distribution<double>{lower_bound, upper_bound}(rng);
}

double ut::distance2V(sf::Vector2f point1, sf::Vector2f point2)
{
    return std::hypot(point1.x - point2.x, point1.y - point2.y);
}