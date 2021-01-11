#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

// Experimental class: might delete
// derived from sf::Text with some extra utils like is_visible etc.

class Message : public sf::Text
{
private:

    sf::Font _font;
    bool _is_visible;
public:

    Message(std::string = "Fonts/Arial.ttf");
    ~Message();

    bool getVisibility();
    void setVisibility(bool);
};