
#include "character.h"


Character::Character()
{   
    if(!mTexture.loadFromFile("IndianaJonesCanva.png"))
        {
            std::cout << "Error opening file\n";
            exit(1);
        }

    mCharacter.setTexture(mTexture);
    mPosition = {0,0};
    mCharacter.setPosition(mPosition);

    // get size of internet image
    sf::Vector2u imageSize = mTexture.getSize();

    // Sets the Jones Character to a size that is proportional to the internet image and has height of 16
    int mHeight = 16;
    int mWidth = (imageSize.x / imageSize.y) * mHeight;
    sf::Vector2u mSize = {mWidth, mHeight};
    /* The setOrigin function sets the origin's 'x' coordinate to 75% of the sprite's size, and it's y coorinate
        to zero. This setup gets the character positioned at the center of the squares, and staying in the same
        spot when turning around. */
    mCharacter.setOrigin(sf::Vector2f(mSize.x * 0.75, 0));
    std::cout<<"Origin: "<<mSize.x<<", "<< mSize.y<<std::endl;

}