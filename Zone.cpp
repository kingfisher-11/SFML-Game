#include "Zone.hpp"


Zone::Zone()
{
    this->setFillColor(sf::Color::Black);
    this->setOutlineColor(sf::Color::Red);
    this->setOutlineThickness(2.0);

    this->setRadius(_radius);
    this->setOrigin(_radius, _radius);
}

Zone::~Zone()
{

}


void Zone::update(double dt)
{

}