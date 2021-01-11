#include "Zone.hpp"


Zone::Zone()
{
    this->setFillColor(sf::Color::Black);
    this->setOutlineColor(sf::Color::Red);
    this->setOutlineThickness(2.0);

    this->setRadius(_zone_radius);
    this->setOrigin(_zone_radius, _zone_radius);
}

Zone::~Zone()
{

}


void Zone::update(double dt)
{

}