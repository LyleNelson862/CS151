#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdint.h>
#include <cstdio>
#include <SFML/Graphics.hpp>


class Character: public sf::Sprite
{
public:
    //Default constructor loading texture from file “IndianaJonesCanva.png”
    // Character();
    // Character(sf::Sprite name, sf::Vector2f position, sf::Vector2f size, sf::Texture textureTile);
    // void turnAround();

    void displayCharacter(sf::Sprite name, sf::Texture texture);
};

#endif