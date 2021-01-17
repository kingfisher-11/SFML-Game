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


class Player : public sf::Sprite
{
private:

    double _acceleration = 1000.0; // px / s^2
    double _max_velocity = 500.0; // px / s
    double _velocity;
    double _rotation_speed = 270.0; // degrees / s
    double _collision_circle = 15.0;
    int _score = 0;

    sf::Texture _texture;
    //sf::Sprite _player_sprite;
public:

    Player(sf::Vector2i = {0, 0});
    ~Player();

    const double getAcceleration();
    const double getRotationSpeed();
    const double getVelocity();
    const int getScore();


    void setVelocity(double);
    void setScore(int);

    void update(double, Zone&);
};