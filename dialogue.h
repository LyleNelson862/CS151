#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <string>
#include<cstdlib>

class Dialogue : public sf::Drawable //, public sf::Transformable
{
public:
    Dialogue(std::string font, std::string message,int xPos, int yPos);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void Stop(const Dialogue &obj,int place,int tile,int xPos,int yPos,sf::RenderWindow &window,sf::CircleShape &jim,int &trap);

private:
    sf::RectangleShape mRect;
    sf::Text mText;
    sf::Font mFont;
    sf::Color mTextNormal;
};

#endif