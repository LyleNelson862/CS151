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

 void runGameJones(MyTiles &MapObj, Dialogue &DiaObj, int tile, sf::RenderWindow &window,
                             Character &Jones, int &trap, sf::Event &event, sf::Clock dtClock, int stepcount, int gridLength, int gridWidth);


    private:    //I need to create variables so I don;t need to use main
        sf::Event m_event;
        int m_Gridsize;
        int m_stepcount;
        int mTrap;
        MyTiles map1;
        Dialogue Dia1;





};





#endif
