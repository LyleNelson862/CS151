#include "character.h"

// void displayCharacter(sf::Sprite name, sf::Texture texture)
void Character::displayCharacter(sf::Sprite name, sf::Texture texture)
{
    texture.loadFromFile("IndianaJonesCanva.png");
    name.setTexture(texture);
    name.setScale (0.07, 0.07);
}

Character& Character::turnAround()
{
    int height;
    int width;
    uint8_t tmp[4];
    uint8_t px1;
    uint8_t px2;
    for(int y = 0; y<height; ++y)
    {
        for(int x=0; x<width/2; ++x)
        {
            px1 = (x+y*width);
            px2 = ((width-1-x)+y*width);

            // memcpy(tmp, px1, channels);
            // memcpy(px1, px2, channels);
            // memcpy(px2, px1, channels);
        }
    }
    return *this;
}