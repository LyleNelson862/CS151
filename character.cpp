#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "character.h"

Character::Character()
{
    if (!mTexture.loadFromFile("IndianaJonesCanva.png")) // Gets the texture for the file
    {
        std::cout << "Error opening file\n";
        exit(1);
    }

    mCharacter.setTexture(mTexture); // sets the texture

    sf::Vector2u imageSize = mTexture.getSize(); // I think I need to get the image size for later
    std::cout<<imageSize.x;
    //453
     mCharacter.setTextureRect(sf::IntRect(268,40,307,374));

    
    mPosition = {0, 0};
    mCharacter.setPosition(mPosition.x, mPosition.y); // Sets the postion at 0,0 in the default constructors
    mCharacter.setScale(0.09, 0.09);                  // Setting scale at this for now

    // Trying to fix the size of the image and I need to figure ouut how to reduce the size of the 'whitespace' on the figure.

    // unsigned int mHeight = 0;
    // unsigned int mWidth = (imageSize.x / imageSize.y - 100) * mHeight;
    // sf::Vector2u mSize = {mWidth, mHeight};

    // mCharacter.setOrigin(sf::Vector2f(mSize.x * 0.75, 0));
    //mCharacter.setOrigin(sf::Vector2f(mCharacter.getTexture()->getSize().x * 0.25, 0));

    // Sets the Jones Character to a size that is proportional to the internet image and has height of 16

    /* The setOrigin function sets the origin's 'x' coordinate to 75% of the sprite's size, and it's y coorinate
        to zero. This setup gets the character positioned at the center of the squares, and staying in the same
        spot when turning around. */

    // Tells me the origin for the shape for testing
    //std::cout << "Origin: " << mSize.x << ", " << mSize.y <<s std::endl;

    xPos = 0;
    yPos = 0;
    facing = 'R';
}

void Character::moveJones(sf::RenderWindow &window, sf::Event &event, int gridSize, int &stepcount)
{

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Right)
        {
            if (xPos < 480)
            {
                
                if (facing == 'L')
                {
                     //mCharacter.setOrigin(sf::Vector2f(mCharacter.getTexture()->getSize().x * 0.25, 0));
                    //mCharacter.setRotation(180);
                    mCharacter.scale(1.f, 1.f); // This is a built-in function that flips the image.

                    facing = 'R';
                }
                xPos = xPos + gridSize;
                usleep(9000);
                stepcount++;
            }
        }
        else if (event.key.code == sf::Keyboard::Left)
        {
            
            if (facing == 'R')
            {
                // mCharacter.setOrigin(sf::Vector2f(mCharacter.getTexture()->getSize().x * -0.25, 0));
                //  The problem is that the amount of whitespace creates problems.
                //mCharacter.setRotation(180);
                mCharacter.scale(1.f, 1.f); // This is a built-in function that flips the image.

                facing = 'L';
            }
            
            if (xPos > 0)
            {
                xPos = xPos - gridSize;
                usleep(9000); //delay after moving
                stepcount++;
            }
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            if (yPos < 224)
            {
                yPos = yPos + gridSize; //moves it the length of the gridsize
                usleep(9000);

                stepcount++;
            }
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
            if (yPos > 0)
            {
                yPos = yPos - gridSize;
                usleep(9000);

                stepcount++;
            }
        }
    }
}
