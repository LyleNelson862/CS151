#include "game.h"
#include "character.h"
#include "dialogue.h"
#include "play.h"
#include <iostream>

int main()
{

    // create the window

    sf::Clock dtClock;
    float dt = 0.f;
    // Clock used to help fix the input
    sf::RenderWindow window(sf::VideoMode(512, 256), "Adventure?");

    int trap2 = 0;
    int stepcount = 0;

    playGame Adventure;

    // Runs the game

    Adventure.runGameJones(70, window, trap2, dtClock, stepcount);

    // std::cout<<tileNum;
    return 0;
}
