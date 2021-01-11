#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>
#include <string>

#include "Player.hpp"
#include "Message.hpp"
#include "Zone.hpp"


class Game
{
private:

    // control for game state
    bool _is_game_running = true;

    // objects
    Message _debug_message;
    Player _player;
    Zone _zone;
    sf::CircleShape _circle;

    // rendering utils
    sf::RenderWindow _game_window;
    sf::View _game_view;
    sf::View _HUD_view;

    // game time management
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