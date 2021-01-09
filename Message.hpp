#pragma once

#include "SFML/Graphics.hpp"

// Experimental class: might delete
// derived from sf::Text with some extra utils like is_visible etc.

class Message : public sf::Text
{
private:

    sf::Font _font;
    bool _is_visible;
public:

    Message(std::string);
    ~Message();

    bool getVisibility();
    void setVisibility(bool);
};