#pragma once

#include "SFML/Graphics.hpp"
#include <list>


class GameWindow : public sf::RenderWindow
{
private:

    std::list <sf::Drawable*> _entities; 
public:

    GameWindow(std::list <sf::Drawable> &entities);
    ~GameWindow();

    void render();
};