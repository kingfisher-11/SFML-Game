#include "Player.hpp"


Player::Player(sf::Vector2i player_coordinates)
{
    _texture.loadFromFile("Media/Player.png");

    this->setTexture(_texture);

    this->setScale({1.2, 1.2});

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

const double Player::getRadius()
{
    return _collision_circle;
}

const int Player::getScore()
{
    return _score;
}


void Player::setVelocity(double velocity)
{
    _velocity = std::max(std::min(velocity, _max_velocity), 0.0);
}

void Player::addPoints(uint points)
{
    _score += points;
}


void Player::update(double dt, Zone &zone)
{
    // Move based on orientation
    double sprite_angle = (this->getRotation() - 90) * M_PI / 180;
    this->move(cos(sprite_angle) * _velocity * dt, sin(sprite_angle) * _velocity * dt);
}