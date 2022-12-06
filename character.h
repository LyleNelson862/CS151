#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <string>
#include<cstdlib>
#include "button.h"
#include "game.h"


class Character: public sf::Sprite, public sf::Texture
{
public:
    //Default constructor loading texture from file “IndianaJonesCanva.png”
    Character();
    // Character(sf::Vector2f position, sf::Vector2f size, sf::Texture texture);

    void moveJones(sf::RenderWindow &window, sf::Event &event,int gridSize, int &stepcount);
     //void runGameJones(MyTiles &MapObj, Dialogue &DiaObj,int tile,sf::RenderWindow &window,
    //Character &Jones,int &trap,sf::Event &event,sf::Clock dtClock,int stepcount,int gridLength,int gridWidth);


    sf::Sprite mCharacter; //I am an idiot I forgot that I needed to actually draw the charcter. I put this in public because I think it would work better
      int xPos;
    int yPos; // Making this public to see if I can solve problems.
private:
  
    char facing;
    int stepcount = 0;
    sf::Vector2f mPosition;
    sf::Texture mTexture;
    sf::Texture mHeight;
    sf::Texture mWidth;
    sf::Vector2f mSize;
};

#endif


