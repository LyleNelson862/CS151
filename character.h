#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdint.h>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include <iostream>


class Character: public sf::Sprite
{
public:
    //Default constructor loading texture from file “IndianaJonesCanva.png”
    Character();
    // Character(sf::Vector2f position, sf::Vector2f size, sf::Texture texture);
    ~Character();


private:
    sf::Sprite mCharacter;
    sf::Vector2f mPosition;
    sf::Texture mTexture;
    // unsigned int mHeight;
    // unsigned int mWidth;
    sf::Vector2u mSize;
};

#endif


