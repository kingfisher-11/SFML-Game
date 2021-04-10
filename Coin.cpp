#include "Coin.hpp"


Coin::Coin(Zone &zone)
{
    // pointer to zone in game class
    _zone = &zone;

    // randomly generated size, position etc.
    // 100 is subtracted from distance to ensure that coins are at least 100 px from zone border
    uint angle = ut::randInt(0, 360);
    uint distance_from_origin = ut::randInt(0, std::max(_zone->getRadius() - this->getRadius() - 100, 0.f));

    this->setRotation(ut::randInt(0, 360));
    this->setRadius(ut::randInt(_min_radius, _max_radius));
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
    _zone = nullptr;
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

        case vanishing:

            this->setFillColor({255, 255, 0, sf::Uint8(std::max(0, this->getFillColor().a - int(1000 * dt)))});

            if(this->getFillColor().a == 0)
            {
                _state = vanished;
            }

            // break is missing to continue animation while coin is dissappearing

        case idle:

            if(_state == idle)
            {
                this->setFillColor({255, 255, 0, sf::Uint8(50 * cos(2 * _elapsed) + 205)});
            }
            this->rotate(sin(_elapsed / 2));

            break;


        
        default:
            break;
    }
}

void Coin::setVanishing()
{
    _state = vanishing;
}

bool Coin::isVanished()
{
    return _state == vanished;
}

bool Coin::isVanishing()
{
    return _state == vanishing;
}