#include "Zone.hpp"


Zone::Zone()
{
    this->setFillColor(sf::Color::Transparent);
    this->setOutlineColor(sf::Color::Transparent);
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

    //particle updates
    while(_particles.size() < this->getRadius() + 100)
    {
        double angle = (double)ut::randInt(0, 3600) / 10.0;
        _particles.push_back(sf::Vector2f(this->getRadius() * cos(angle), this->getRadius() * sin(angle)));
    }

    for(auto it = _particles.begin(); it != _particles.end();)
    {
        it->update(dt);

        if(it->expired())
        {
            it = _particles.erase(it);
        }
        else
        {
            it++;
        }   
    }

    // state based changes
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

const std::list<ZoneParticle> &Zone::getParticles()
{
    return _particles;
}