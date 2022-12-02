#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "character.h"
#include "stb_character.h"
#include "stb_character_write.h"


// void displayCharacter(sf::Sprite name, sf::Texture texture)
void Character::displayCharacter(sf::Sprite name, sf::Texture texture)
{
    texture.loadFromFile("IndianaJonesCanva.png");
    name.setTexture(texture);
    name.setScale (0.07, 0.07);
}


    // Character::Character(const char* filename)
    // {
    //     if(read(filename)){
    //         printf("Read%s\n", filename);
    //     }
    //     else{
    //         printf("Failed to read%s\n", filename);
    //     }
    // }
    // Character::Character(int width, int height, int channels)
    // {
    //     size = width*height*channels;
    //     data = new uint8_t[size];
    // }
    // Character::Character(const Character& img) : Character(img.width, img.height, img.channels)
    // {
    //     memcpy(data, img.data, img.size);
    // }
    // Character::~Character()
    // {
    //     stbi_image_free(data);
    // }
    // bool Character::read(const char* filename)
    // {

    // }
    // bool write(const char* filename);
    
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
            // px1 = &data[(x+y*width)*channels];
            // px2 = &data[((width-1-x)+y*width)*channels];

            // memcpy(tmp, px1, channels);
            // memcpy(px1, px2, channels);
            // memcpy(px2, px1, channels);
        }
    }
    return *this;
}