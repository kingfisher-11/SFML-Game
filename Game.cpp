#include "Game.hpp"


Game::Game()
:_coin_manager(_zone, _player)
{
    _game_window.create(sf::VideoMode(800, 600), "Game");
    _game_window.setFramerateLimit(60);

    _game_view.setSize(sf::Vector2f(_game_window.getSize()));

    _HUD_view.setSize(sf::Vector2f(_game_window.getSize()));

    _circle.setRadius(100.0);
    _circle.setOrigin(sf::Vector2f(100.0, 100.0));
    _circle.setFillColor(sf::Color::Green);

    _scoreboard.setFillColor({255, 255, 255, 150});

    _debug_message.setPosition(0, 20);
    _debug_message.setVisibility(0);

    _coin_target = 1;

    // for testing
    //_game_window.setFramerateLimit(10);
}

Game::~Game()
{
    _game_window.close();
}


void Game::run()
{
    while(_is_game_running)
    {
        getInput();
        update();
        render();
    }
}

void Game::updateDt()
{
    // Update delta time
    _dt = _game_clock.restart().asSeconds();
}

void Game::getInput()
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
                        break;

                    case sf::Keyboard::Equal:
                        _player.setScore(INT16_MAX);
                        break;
                    
                    default:
                        break;
                }
            
            default:
                break;
        }
    }


    // Mouse input
    sf::Vector2f mouse_coords = _game_window.mapPixelToCoords(sf::Mouse::getPosition(_game_window), _game_view);

    double target_rotation = ut::degrees2V({(float)sin(_player.getRotation() * M_PI / 180), (float)-cos(_player.getRotation() * M_PI / 180)}, mouse_coords - _player.getPosition());

    _player.rotate(target_rotation >= 0 ? std::min(target_rotation * 10 * _dt, _player.getRotationSpeed() * _dt) : std::max(target_rotation * 10 * _dt, -_player.getRotationSpeed() * _dt));

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        _player.setVelocity(_player.getVelocity() + _player.getAcceleration() * _dt);
    }
    else
    {
        _player.setVelocity(_player.getVelocity() - _player.getAcceleration() * _dt);
    }
    
}

void Game::update()
{
    updateDt();

    _zone.update(_dt);

    _player.update(_dt, _zone);

    _coin_manager.update(_dt);

    _game_view.setCenter(_player.getPosition());

    //manage reaching target score
    if(_player.getScore() >= _coin_target)
    {
        _coin_target += 10;
        _player.setScore(0);
        _zone.setExpanding();
    }


    //collision detection
    //player
    if(ut::distance2V(_player.getPosition(), _zone.getPosition()) > _zone.getRadius() - _player.getRadius())
    {
        _player.setColor(sf::Color::Green);
    }
    else
    {
        _player.setColor(sf::Color::Red);
    }
    
    // update messages
    std::string debug_coordinates_string = "X: " + std::to_string(int(_player.getPosition().x)) + "\nY: " + std::to_string(int(_player.getPosition().y));
    _debug_message.setString(debug_coordinates_string);

    _scoreboard.setString(std::to_string(_player.getScore()));

    sf::FloatRect score_rect = _scoreboard.getLocalBounds();
    _scoreboard.setOrigin(score_rect.left + score_rect.width / 2, score_rect.top + score_rect.height / 2);
    _scoreboard.setPosition(_player.getPosition().x, _player.getPosition().y + 80);
}

void Game::render()
{
    _game_window.clear(sf::Color::Black);


    // game view
    _game_window.setView(_game_view);

    _game_window.draw(_circle);

    _game_window.draw(_zone);

    for(auto it : _zone.getParticles())
    {
        _game_window.draw(it);
    }

    for(auto it : _coin_manager.getCoins())
    {
        _game_window.draw(it);
    }

    _game_window.draw(_scoreboard);

    _game_window.draw(_player);

    // interface view
    _game_window.setView(_HUD_view);

    if(_debug_message.getVisibility())
        _game_window.draw(_debug_message);


    _game_window.display();
}