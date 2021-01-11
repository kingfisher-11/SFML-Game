#include "Player.hpp"


Player::Player(sf::Vector2i player_coordinates)
{
    _player_texture.loadFromFile("Media/Player.png");

    _player_sprite.setTexture(_player_texture);

    _player_sprite.setPosition(sf::Vector2f(player_coordinates));

    _player_sprite.setOrigin(sf::Vector2f(15.0, 25.0));
}

Player::~Player()
{
    
}


sf::Sprite &Player::getSprite()
{
    return _player_sprite;
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
    double sprite_angle = (_player_sprite.getRotation() - 90) * M_PI / 180;
    _player_sprite.move(cos(sprite_angle) * _player_velocity * dt, sin(sprite_angle) * _player_velocity * dt);  

    // Check if player is outside of zone
    double distance_from_zone = std::hypot(_player_sprite.getPosition().x - zone.getPosition().x, _player_sprite.getPosition().y - zone.getPosition().y);
    
    if(distance_from_zone > zone.getRadius() - _player_collision_circle)
    {
        _player_sprite.setColor(sf::Color::Green);
    }
    else
    {
        _player_sprite.setColor(sf::Color::Red);
    }
    

    _player_sprite.setRotation(_player_rotation);
}