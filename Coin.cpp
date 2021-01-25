#include "Coin.hpp"


void Coin::spawnAnimation(double dt)
{
    this->rotate(pow(dt / 2 - 5, 2));
}


Coin::Coin()
{
    // randomly generated size, position etc.
    // 50 is subtracted from distance to ensure that coins are at least 50 px from zone border
    uint angle = Utilities::randInt(0, 360);
    uint distance_from_origin = Utilities::randInt(0, Zone::_radius - this->getRadius() - 50) ;

    this->setRotation(Utilities::randInt(0, 360));
    this->setRadius(Utilities::randInt(_min_radius, _max_radius));
    this->setPosition(distance_from_origin * sin(angle), distance_from_origin * cos(angle));


    // set values for color, shape, origin
    this->setOrigin(this->getRadius(), this->getRadius());
    this->setPointCount(3);
    this->setFillColor({255, 200, 0, 255});


    // set coin state
    _state = spawning;
}

Coin::~Coin()
{

}


void Coin::update(double dt)
{
    _elapsed += dt;

    switch(_state)
    {
        case spawning:
            
            this->setFillColor({255, 255, 0, sf::Uint8(std::min(_elapsed, 3.0) * 85)});
            this->rotate(pow(2, 6 - 4 * _elapsed));

            if(_elapsed > 3.0)
            {
                _elapsed = 0.0;
                _state = idle;
            }

            break;

        case idle:

            this->setFillColor({255, 255, 0, sf::Uint8(50 * cos(2 * _elapsed) + 205)});
            this->rotate(sin(_elapsed / 2));

            break;
    }
}