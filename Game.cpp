#include "Game.hpp"


Game::Game()
{
    _game_window.create(sf::VideoMode(800, 600), "Game");

    _game_window.setFramerateLimit(60);

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
        updateDt();

        updateSfmlEvents();

        update();

        render();
    }
}

void Game::updateDt()
{
    // Update delta time
    _dt = _game_clock.restart().asSeconds();
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
        _player->updatePlayerVelocity(500.0, _dt);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _player->updatePlayerVelocity(-500.0, _dt);
    }
    else
    {
        _player->updatePlayerVelocity(-250.0, _dt);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _player->updatePlayerRotation(-180.0, _dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _player->updatePlayerRotation(180.0, _dt);
    }
}

void Game::update()
{
    //system("clear");
    //std::cout << _dt << std::endl;

    _player->update(_dt);
}

void Game::render()
{
    _game_window.clear(sf::Color::Black);

    _game_window.draw(_player->getSprite());

    _game_window.display();
}