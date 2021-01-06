#include "Player.hpp"


Player::Player(sf::Vector2i player_coordinates)
{
    _player_texture.loadFromFile("Media/Player.png");

    _player_sprite.setTexture(_player_texture);

    _player_sprite.setPosition(sf::Vector2f(player_coordinates));
}

Player::~Player()
{

}


sf::Sprite Player::getSprite()
{
    return _player_sprite;
}

void Player::updatePlayerVelocity(sf::Vector2f)
{
    
}