#include "Coin.hpp"


Coin::Coin(const Zone &zone, sf::Vector2f position)
:_zone(zone)
{
    // randomly generated size, position etc.
    // 100 is subtracted from distance to ensure that coins are at least 100 px from zone border
    uint angle = ut::randInt(0, 360);
    uint distance_from_origin = ut::randInt(0, std::max(_zone.getRadius() - this->getRadius() - 100, 0.f));

    this->setRotation(ut::randInt(0, 360));
    this->setRadius(ut::randInt(_min_radius, _max_radius));
    this->setPosition(position);
    _rotation_speed = ut::randInt(45, 180);


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
            this->rotate(360 * (1.74 - sqrt(_elapsed)) * dt);

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
            this->rotate(_rotation_speed * sin(0.5 * _elapsed) * dt);

            break;

        default:
            break;
    }
}

void Coin::setVanishing()
{
    _state = vanishing;
}

bool Coin::isVanished() const
{
    return _state == vanished;
}

bool Coin::isVanishing() const
{
    return _state == vanishing;
}