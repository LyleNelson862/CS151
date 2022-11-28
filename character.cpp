#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "character.h"


// void displayCharacter(sf::Sprite name, sf::Texture texture)
void Character::displayCharacter(sf::Sprite name, sf::Texture texture)
{
    texture.loadFromFile("IndianaJonesCanva.png");
    name.setTexture(texture);
    name.setScale (0.08, 0.08);
}
