#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "character.h"

Character::Character()
{
    if (!mTexture.loadFromFile("IndianaJonesCanva.png"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }

    mCharacter.setTexture(mTexture);

    sf::Vector2u imageSize = mTexture.getSize();
    unsigned int mHeight = 16;
    unsigned int mWidth = (imageSize.x / imageSize.y) * mHeight;
    sf::Vector2u mSize = {mWidth, mHeight};

    mCharacter.setOrigin(sf::Vector2f(mSize.x * 0.75, 0));

    mPosition = {0, 0};
    mCharacter.setPosition(mPosition.x,mPosition.y);
    mCharacter.setScale(0.1, 0.1);

    // get size of internet image

    // Sets the Jones Character to a size that is proportional to the internet image and has height of 16

    /* The setOrigin function sets the origin's 'x' coordinate to 75% of the sprite's size, and it's y coorinate
        to zero. This setup gets the character positioned at the center of the squares, and staying in the same
        spot when turning around. */
    std::cout << "Origin: " << mSize.x << ", " << mSize.y << std::endl;

    xPos=0;
    yPos=0;
}

void Character:: moveJones(sf::RenderWindow &window, sf::Event &event, int gridSize, int &stepcount)
{

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Right)
        {
            if (xPos < 480)
            {
                xPos = xPos + gridSize;
                usleep(9000);
                stepcount++;

            }
        }
        else if (event.key.code == sf::Keyboard::Left)
        {
            if (xPos > 0)
            {
                xPos = xPos - gridSize;
                usleep(9000);
                stepcount++;
            }
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            if (yPos < 224)
            {
                yPos = yPos + gridSize;
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




    void Character::runGameJones(MyTiles &MapObj,/* Dialogue &DiaObj*/int tile,sf::RenderWindow &window,
    Character &Jones,int &trap,sf::Event &event,sf::Clock dtClock,int stepcount,int gridLength,int gridWidth) //moved becuase it is a long line
    {
         while (window.isOpen())
    {
        // Updating dt

        //dt = dtClock.restart().asSeconds();

        // handle events
        
           while (window.pollEvent(event))
           {
               if (event.type == sf::Event::Closed)
               {
                   window.close();

               }

             Jones.moveJones(window,event,gridLength,stepcount);


           }
       

        // Render the map and the game elements.
        window.clear();
        window.draw(MapObj);

        window.draw(Jones.mCharacter);
        window.display();

        int place = MapObj.findTile(xPos, yPos, gridLength, gridWidth);

        //DiaObj.StopJones(DiaObj, place, 70, xPos, yPos, window, Jones, trap, event);
        mCharacter.setPosition(xPos, yPos);
        // End of while loops
    }
    }