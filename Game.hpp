#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>

#include "Player.hpp"



class Game
{
private:

    Player *_player;

    sf::RenderWindow _game_window;

    sf::Clock _game_clock;
    double _dt;
public:

    Game();
    ~Game();

    void run();

    void updateDt();
    void updateSfmlEvents();
    void update();
    void render();
};