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

    double _acceleration = 1000.0;
    double _max_velocity = 800.0;
    double _velocity;
    double _rotation_speed = 5.0;
    double _collision_circle = 30.0;
    uint _score = 0;

    sf::Texture _texture;
    //sf::Sprite _player_sprite;
public:

    Player(sf::Vector2i = {0, 0});
    ~Player();

    double getAcceleration() const;
    double getRotationSpeed() const;
    double getVelocity() const;
    double getRadius() const;
    int getScore() const;

    void setVelocity(double);
    void setScore(uint);

    void update(double, Zone&);
};