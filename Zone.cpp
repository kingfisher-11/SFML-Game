#include "Zone.hpp"


Zone::Zone()
{
    this->setFillColor(sf::Color::Black);
    this->setOutlineColor(sf::Color::Red);
    this->setOutlineThickness(2.0);

    this->setRadius(_max_radius);
    this->setOrigin(_max_radius, _max_radius);
}

Zone::~Zone()
{

}


void Zone::update(double dt)
{
    
}