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


double Player::getAcceleration() const
{
    return _acceleration;
}

double Player::getRotationSpeed() const
{
    return _rotation_speed;
}

double Player::getVelocity() const
{
    return _velocity;
}

double Player::getRadius() const
{
    return _collision_circle;
}

int Player::getScore() const
{
    return _score;
}


void Player::setVelocity(double velocity)
{
    _velocity = std::max(std::min(velocity, _max_velocity), 0.0);
}

void Player::setScore(uint score)
{
    _score = score;
}


void Player::update(double dt, Zone &zone)
{
    // Move based on orientation
    double sprite_angle = (this->getRotation() - 90) * M_PI / 180;
    this->move(cos(sprite_angle) * _velocity * dt, sin(sprite_angle) * _velocity * dt);
}