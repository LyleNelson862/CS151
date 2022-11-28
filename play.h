#ifndef PLAY_H
#define PLAY_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <string>
#include<cstdlib>
#include "button.h"
#include "game.h"
#include "dialogue.h"
    

    //void move(sf::RenderWindow &window,sf::Event &event,int &xPos,int &yPos,int gridSize,int &stepcount);

class playGame //: sf::Drawable
{
    public:
    //playGame();  working on default constructor  for these things

    void move(sf::RenderWindow &window, sf::Event &event, int &xPos, int &yPos, int gridSize, int &stepcount); // Moves the shape
    void runGame(playGame &gameObj, MyTiles &MapObj, Dialogue &DiaObj,int tile,int xPos,int yPos,sf::RenderWindow &window,sf::CircleShape &jim,int &trap,sf::Event &event,sf::Clock dtClock,int stepcount,int gridLength,int gridWidth);

    // Another problem is that i need to know if 



    private:    //I need to create variables so I don;t need to use main
    sf::Event m_event;
    int m_Xpos;
    int m_Ypos;
    int m_Gridsize;
    int m_stepcount;
    int mTrap;
    sf::CircleShape mJim;

    MyTiles map1;
    Dialogue Dia1;





};





#endif