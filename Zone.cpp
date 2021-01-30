#include "Zone.hpp"


Zone::Zone()
{
    this->setFillColor(sf::Color::Transparent);
    this->setOutlineColor(sf::Color::Red);
    this->setOutlineThickness(2.0);

    this->setRadius(_max_radius);
    this->setOrigin(_max_radius, _max_radius);
    //this->setPosition(_max_radius, _max_radius);

    _state = shrinking;
}

Zone::~Zone()
{

}


void Zone::update(double dt)
{
    _elapsed += dt;

    switch(_state)
    {
        case shrinking:

            this->setRadius(this->getRadius() - (pow(this->getRadius(), 0.5) + 0.1) * dt);
            this->setOrigin(this->getRadius(), this->getRadius());
            break;

        case expanding:

            break;
    }
}