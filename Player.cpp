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

void Player::updatePlayerVelocity(double acceleration, double dt)
{
    _player_velocity += acceleration * dt;

    _player_velocity = std::min(_player_velocity, 500.0);
    _player_velocity = std::max(_player_velocity, 0.0);
}

void Player::updatePlayerRotation(double angle_change, double dt)
{
    _player_rotation += angle_change * dt;
}

void Player::update(double dt)
{
    // Move based on orientation
    double sprite_angle = (_player_sprite.getRotation() - 90) * M_PI / 180;
    _player_sprite.move(cos(sprite_angle) * _player_velocity * dt, sin(sprite_angle) * _player_velocity * dt);

    debugPrint(_player_velocity);

    _player_sprite.setRotation(_player_rotation);
}