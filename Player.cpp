#include "Player.hpp"


Player::Player(sf::Vector2i player_coordinates)
{
    _player_texture.loadFromFile("Media/Player.png");

    this->setTexture(_player_texture);

    this->setPosition(sf::Vector2f(player_coordinates));

    this->setOrigin(sf::Vector2f(15.0, 25.0));
}

Player::~Player()
{
    
}


const double Player::getAcceleration()
{
    return _player_acceleration;
}

const double Player::getRotationSpeed()
{
    return _player_rotation_speed;
}


void Player::updatePlayerVelocity(double acceleration, double dt)
{
    _player_velocity += acceleration * dt;

    _player_velocity = std::min(_player_velocity, _max_player_velocity);
    _player_velocity = std::max(_player_velocity, 0.0);
}

void Player::updatePlayerRotation(double angle_change, double dt)
{
    _player_rotation += angle_change * dt;
}

void Player::update(double dt, Zone &zone)
{
    // Move based on orientation
    double sprite_angle = (this->getRotation() - 90) * M_PI / 180;
    this->move(cos(sprite_angle) * _player_velocity * dt, sin(sprite_angle) * _player_velocity * dt);  

    // Check if player is outside of zone
    double distance_from_zone = std::hypot(this->getPosition().x - zone.getPosition().x, this->getPosition().y - zone.getPosition().y);
    
    if(distance_from_zone > zone.getRadius() - _player_collision_circle)
    {
        this->setColor(sf::Color::Green);
    }
    else
    {
        this->setColor(sf::Color::Red);
    }
    

    this->setRotation(_player_rotation);
}