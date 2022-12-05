#include "character.h"

Character::Character()
{   
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");
    if(!mTexture.loadFromFile("IndianaJonesCanva.png"))
        {
            std::cout << "Error opening file\n";
            exit(1);
        }

    mCharacter.setTexture(mTexture);
    mPosition.x = 0;
    mPosition.y = 0;
    mCharacter.setPosition(mPosition);
    window.clear();
    // window.draw(map);
    window.draw(mCharacter);


    // get size of internet image
    mImageSize = mTexture.getSize();

    // Sets the Jones Character to a size that is proportional to the internet image and has height of 16
    mGameSize.x = 16;
    mGameSize.y = (mImageSize.x / mImageSize.y) * mGameSize.x;
    // mSize = {mHeight, mWidth};
    // mSize.x = mHeight

    /* The setOrigin function sets the origin's 'x' coordinate to 75% of the sprite's size, and it's y coorinate
        to zero. This setup gets the character positioned at the center of the squares, and staying in the same
        spot when turning around. */
    mCharacter.setOrigin(sf::Vector2f(mGameSize.x * 0.75, 0));
    std::cout<<"Origin: "<<mGameSize.x<<", "<< mGameSize.y<<std::endl;
}

    // Character(sf::Vector2f position, sf::Vector2f size, sf::Texture texture)
    // {

    // }


// The quick fix is to add -std=c++17 to support this C++ feature.

// The actual fix is to use C++ more effectively, like employing a std::vector plus using emplace_back to create entries as necessary:

// // Malloc the list of conditions to be met
// std::vector<Cond> condList;

// for (int i= 0; i < numConds; ++i) {
//   condList.emplace_back(
//     0, // int offset1
//     nullptr, // bool (*comparator) (void * , void *, AttrType, int); 
//     true, // bool isValue;
//     nullptr, // void* data; 
//     0, // int offset2; 
//     0, // int length; 
//     0, // int length2; 
//     INT // AttrType type; 
//   );
// }
