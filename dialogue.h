#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <string>

class Dialogue //: public sf::Drawable, public sf::Transformable
{
public:
    Dialogue(std::string font, std::string message,int xPos, int yPos);

        std::string mTest;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::Text m_text;
    sf::Text mText;
    sf::Font mFont;
    sf::Color mTextNormal;
};

#endif