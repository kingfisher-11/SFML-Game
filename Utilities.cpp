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

double ut::degrees2V(sf::Vector2f point1, sf::Vector2f point2)
{
    double angle = atan2(point2.x - point1.x, point1.y - point2.y) * 180 / M_PI + 360;

    //system("clear");
    //std::cout << point1.x << "_" << point1.y << std::endl;
    //std::cout << point2.x << "_" << point2.y << std::endl;

    //return angle;

    //return angle <= 360 ? angle : angle - 360;

    double dot_product = point1.x * point2.x + point1.y * point2.y;
    double cross_product = -point1.x * point2.y + point1.y * point2.x;
    int8_t side = cross_product >= 0 ? -1 : 1;

    double magnitude1 = sqrt(pow(point1.x, 2) + pow(point1.y, 2));
    double magnitude2 = sqrt(pow(point2.x, 2) + pow(point2.y, 2));

    double output = side * acos(dot_product / (magnitude1 * magnitude2)) * 180 / M_PI;

    return abs(output) < 1 ? 0 : output;
}