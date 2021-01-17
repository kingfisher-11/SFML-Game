#include "Player.hpp"


Player::Player(sf::Vector2i player_coordinates)
{
    _texture.loadFromFile("Media/Player.png");

    this->setTexture(_texture);

    this->setPosition(sf::Vector2f(player_coordinates));

    this->setOrigin(sf::Vector2f(15.0, 25.0));
}

Player::~Player()
{
    
}


const double Player::getAcceleration()
{
    return _acceleration;
}

const double Player::getRotationSpeed()
{
    return _rotation_speed;
}

const double Player::getVelocity()
{
    return _velocity;
}

const int Player::getScore()
{
    return _score;
}


void Player::setVelocity(double velocity)
{
    _velocity = std::max(std::min(velocity, _max_velocity), 0.0);
}

void Player::setScore(int score)
{
    _score = score;
}


void Player::update(double dt, Zone &zone)
{
    // Move based on orientation
    double sprite_angle = (this->getRotation() - 90) * M_PI / 180;
    this->move(cos(sprite_angle) * _velocity * dt, sin(sprite_angle) * _velocity * dt);  

    // Check if player is outside of zone
    double distance_from_zone = std::hypot(this->getPosition().x - zone.getPosition().x, this->getPosition().y - zone.getPosition().y);
    
    if(distance_from_zone > zone.getRadius() - _collision_circle)
    {
        this->setColor(sf::Color::Green);
    }
    else
    {
        this->setColor(sf::Color::Red);
    }
}