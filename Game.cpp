#include "Game.hpp"


Game::Game()
{
    _game_window.create(sf::VideoMode(800, 600), "Game");

    _game_clock.restart();

    _player = new Player(sf::Vector2i(_game_window.getSize()) / 2);
}

Game::~Game()
{

}


void Game::run()
{
    while(_game_window.isOpen())
    {
        updateSfmlEvents();

        update();

        render();
    }
}

void Game::updateSfmlEvents()
{
    sf::Event event;

    while(_game_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            _game_window.close();
        }
    }


    // Keyboard Input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        
    }
}

void Game::update()
{

}

void Game::render()
{
    _game_window.clear(sf::Color::Black);

    _game_window.draw(_player->getSprite());

    _game_window.display();
}