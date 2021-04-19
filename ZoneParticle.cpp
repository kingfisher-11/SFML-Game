#include "ZoneParticle.hpp"


ZoneParticle::ZoneParticle(sf::Vector2f position)
{
    this->setPosition(position);
    this->setSize({10.0, 10.0});
    this->setFillColor(sf::Color::Red);

    // initialize random values for attributes
    _lifespan = ut::randDouble(0.1, 1.0);
    _velocity = {(float)ut::randDouble(-30.0, 30.0), (float)ut::randDouble(-30.0, 30.0)};
}

ZoneParticle::~ZoneParticle()
{

}


void ZoneParticle::update(double dt)
{
    _elapsed += dt;

    // object deletion is handled in Zone class
    if(_elapsed > _lifespan)
    {
        _expired = true;
    }

    this->move(_velocity * (float)dt);
    this->setFillColor({255, 0, 0, sf::Uint8(sin(M_PI * _elapsed / _lifespan) * 255)});
}

bool &ZoneParticle::expired()
{
    return _expired;
}