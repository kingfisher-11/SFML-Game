#pragma once

#include "SFML/Graphics.hpp"


class Player
{
private:

    sf::Texture _player_texture;
    sf::Sprite _player_sprite;

    sf::Vector2f _player_velocity;
public:

    Player(sf::Vector2i);
    ~Player();

    sf::Sprite getSprite();
    void updatePlayerVelocity(sf::Vector2f);
};