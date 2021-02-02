#include "ZoneParticle.hpp"


ZoneParticle::ZoneParticle(sf::Vector2f position)
{
    this->setPosition(position);
    this->setSize({10.0, 10.0});
    this->setFillColor(sf::Color::Red);

    // initialize random values for attributes
    _lifespan = (double)ut::randInt(1, 20) / 10.0;
    _velocity = {(float)ut::randInt(-300, 300) / 10.f, (float)ut::randInt(-300, 300) / 10.f};
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
    this->setFillColor({255, 0, 0, sin(M_PI * _elapsed / _lifespan) * 255});
}

bool &ZoneParticle::expired()
{
    return _expired;
}