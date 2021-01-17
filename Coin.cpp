#include "Coin.hpp"


void Coin::spawnAnimation()
{

}


Coin::Coin()
{
    // set values for color, shape, origin
    this->setOrigin(this->getRadius(), this->getRadius());
    this->setPointCount(3);
    this->setFillColor({255, 200, 0, 255});

    // randomly generated size, position etc.
    // 50 is subtracted from distance to ensure that coins are at least 50 px from zone border
    uint angle = Utilities::randInt(0, 360);
    uint distance_from_origin = Utilities::randInt(0, Zone::_radius - this->getRadius() - 50) ;

    this->setRotation(Utilities::randInt(0, 360));
    this->setRadius(Utilities::randInt(_min_radius, _max_radius));
    this->setPosition(distance_from_origin * sin(angle), distance_from_origin * cos(angle));
}

Coin::~Coin()
{

}


void Coin::update(double dt)
{
    
}