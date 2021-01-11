#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>

#include "Zone.hpp"


template <class T>
void debugPrint(T str)
{
    system("clear");
    std::cout << str << std::endl;
}


class Player
{
private:

    const double _max_player_velocity = 1000.0; // px / s
    const double _player_acceleration = 1000.0; // px / s^2
    const double _player_rotation_speed = 270.0; // degrees / s
    const double _player_collision_circle = 15.0;

    sf::Texture _player_texture;
    sf::Sprite _player_sprite;

    double _player_velocity;
    double _player_rotation;
public:

    Player(sf::Vector2i = {0, 0});
    ~Player();

    sf::Sprite &getSprite();
    const double getAcceleration();
    const double getRotationSpeed();

    void updatePlayerVelocity(double, double);
    void updatePlayerRotation(double, double);

    void update(double, Zone&);
};