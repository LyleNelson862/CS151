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
     playGame();
    void move(sf::RenderWindow &window, sf::Event &event, int &xPos, int &yPos, int gridSize, int &stepcount);

    void RunGame(sf::RenderWindow &window);

    private:

};





#endif