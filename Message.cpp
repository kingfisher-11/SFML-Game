#include "Message.hpp"


Message::Message(std::string font_file_path)
{
    _is_visible = true;

    if(!_font.loadFromFile(font_file_path))
    {
        std::cout << "Font file missing" << std::endl;
    }

    this->setFont(_font);
    this->setString("Hello");
    this->setCharacterSize(30);
}

Message::~Message()
{

}


bool Message::getVisibility()
{
    return _is_visible;
}

void Message::setVisibility(bool is_visible)
{
    _is_visible = is_visible;
}