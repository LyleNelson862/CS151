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
    Character& turnAround();
    void displayCharacter(sf::Sprite name, sf::Texture texture);
private:
    uint8_t* data = NULL;
    size_t size = 0;
    int width;
    int height;
    int channels;

    // Character(const char* filename);
    // Character(int width, int height, int channels);
    // Character(const Character& img);
    // ~Character();

    bool read(const char* filename);
    bool write(const char* filename);
};

#endif