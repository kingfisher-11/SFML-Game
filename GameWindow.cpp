#include "GameWindow.hpp"


GameWindow::GameWindow(std::list <sf::Drawable> &entities)
{
    for(auto it : entities)
    {
        _entities.push_back(&it);
    }
}

GameWindow::~GameWindow()
{

}


void GameWindow::render()
{

}