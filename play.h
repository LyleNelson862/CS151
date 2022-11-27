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
    //playGame();
    void move(sf::RenderWindow &window, sf::Event &event, int &xPos, int &yPos, int gridSize, int &stepcount); // Moves the shape
    void runGame(playGame &gameObj, MyTiles &MapObj, Dialogue &DiaObj,int tile,int xPos,int yPos,sf::RenderWindow &window,sf::CircleShape &jim,int &trap,sf::Event &event,sf::Clock dtClock,int stepcount,int gridLength,int gridWidth);

    // Another problem is that i need to know if 

    private:
    sf::RenderWindow m_window;
    sf::Event m_event;

};





#endif