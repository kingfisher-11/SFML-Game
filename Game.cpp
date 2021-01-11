#include "Game.hpp"


Game::Game()
{
    _game_window.create(sf::VideoMode(800, 600), "Game");
    _game_window.setFramerateLimit(60);

    _game_view.setSize(sf::Vector2f(_game_window.getSize()));

    _HUD_view.setSize(sf::Vector2f(_game_window.getSize()));

    _circle.setRadius(100.0);
    _circle.setOrigin(sf::Vector2f(100.0, 100.0));
    _circle.setFillColor(sf::Color::Green);
}

Game::~Game()
{
    _game_window.close();
}


void Game::run()
{
    while(_is_game_running)
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
        switch(event.type)
        {
            case sf::Event::Closed:
                _is_game_running = false;
                break;

            // update view to remain consistent with window size
            case sf::Event::Resized:
                _game_view.setSize(event.size.width, event.size.height);
                _HUD_view.reset(sf::FloatRect(0.0, 0.0, event.size.width, event.size.height));
                break;

            // for debug purposes; to be removed for finished game
            case sf::Event::MouseWheelMoved:
                _game_view.zoom(1 - 0.1 * event.mouseWheel.delta);
                break;


            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        _is_game_running = false;
                        break;
                    
                    case sf::Keyboard::F12:
                        _debug_message.setVisibility(!_debug_message.getVisibility());
                    
                    default:
                        break;
                }
            
            default:
                break;
        }
    }


    // Keyboard Input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _player.updatePlayerVelocity(_player.getAcceleration(), _dt);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _player.updatePlayerVelocity(-_player.getAcceleration(), _dt);
    }
    else
    {
        _player.updatePlayerVelocity(-_player.getAcceleration() / 2, _dt);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _player.updatePlayerRotation(-_player.getRotationSpeed(), _dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _player.updatePlayerRotation(_player.getRotationSpeed(), _dt);
    }
}

void Game::update()
{
    // useful intermediate variables
    sf::Vector2f player_position = _player.getPosition();

    _zone.update(_dt);

    _player.update(_dt, _zone);

    _game_view.setCenter(player_position);

    std::string debug_coordinates_string = "X: " + std::to_string(int(player_position.x)) + "\nY: " + std::to_string(int(player_position.y));
    _debug_message.setString(debug_coordinates_string);
}

void Game::render()
{
    _game_window.clear(sf::Color::Black);


    // game view
    _game_window.setView(_game_view);

    _game_window.draw(_zone);

    _game_window.draw(_circle);

    _game_window.draw(_player);

    // interface view
    _game_window.setView(_HUD_view);

    if(_debug_message.getVisibility())
        _game_window.draw(_debug_message);


    _game_window.display();
}