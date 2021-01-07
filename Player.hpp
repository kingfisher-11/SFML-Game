#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>


template <class T>
void debugPrint(T str)
{
    system("clear");
    std::cout << str << std::endl;
}


class Player
{
private:

    sf::Texture _player_texture;
    sf::Sprite _player_sprite;

    double _player_velocity;
    double _player_rotation;
public:

    Player(sf::Vector2i);
    ~Player();

    sf::Sprite &getSprite();
    void updatePlayerVelocity(double, double);
    void updatePlayerRotation(double, double);

    void update(double);
};