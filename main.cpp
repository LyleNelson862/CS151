#include "game.h"
#include "character.h"
#include "dialogue.h"
#include "play.h"
#include <iostream>
 
 
int main()
{
     srand(time(NULL));

    // create the window

    sf::Clock dtClock;
    float dt = 0.f;
    // Clock used to help fix the input
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

    // Creating a shape that can be used

    sf::Texture textureTile;
    textureTile.loadFromFile("IndianaJonesCanva.png");
    Character jones;


    
    // define the level with an array of tile indices

    sf::View view;
    view.setSize(512, 256);
    view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);


     int random = rand() %128;
     //std::cout<<random;
    int trap2 = 0;
    int stepcount =0;

    std::string message = "You notice a strange tile on the ground, and touch it with a 5 foot pole,"
                          " \n you then fall into a pit press Space to escape ";

    Dialogue pit("OpenSans-Regular.ttf", message, 0, 0);
    

    int tileNum;

    
    const int level[] =
    {
        4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        4, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 2, 4, 0, 0, 0,
        1, 1, 4, 4, 4, 43, 4, 9, 3, 3, 3, 31, 3, 35, 3, 3,
        23, 1, 0, 4, 2, 3, 3, 3, 3, 13, 1, 1, 1, 4, 4, 4,
        4, 1, 1, 4, 3, 3, 60, 25, 4, 55, 1, 1, 1, 2, 4, 4,
        4, 4, 1, 41, 3, 4, 18, 2, 4, 4, 1, 1, 1, 1, 2, 4,
        2, 4, 1, 4, 3, 4, 26, 2, 2, 4, 1, 1, 1, 1, 1, 1,
        4, 4, 1, 4, 3, 2, 2, 2, 4, 4, 4, 4, 1, 1, 1, 1,
    };

    
    // create the tilemap from the level definition

    // Need to move this


    float gridLength = 32;
    float gridWidth = 32;
    float viewspeed = 1;
    MyTiles map;

    if (!map.load("rpg_textures.png", sf::Vector2u(gridLength, gridWidth), level, 16, 8))
    {
        return -1;
    }


    sf::RectangleShape Pause(sf::Vector2f(512, 256));
    Pause.setFillColor(sf::Color::Black);
    Pause.setPosition(0, 0);

    // run the main loop
        sf::Event event;

        playGame test;


        //Runs the game

    
        test.runGameJones(map,pit,70,window,jones,trap2,event,dtClock,stepcount,gridLength,gridWidth);     



    //std::cout<<tileNum;
    return 0;


   }

  

/* Old main 
int main() 
{
    srand(time(NULL)); //To generate random see for place when I was testing.

    // Placing a comment in here to check for pushing

    // create the window

    sf::Clock dtClock;
    float dt = 0.f;
    // Clock used to help fix the input
    sf::RenderWindow m_window(sf::VideoMode(512, 256), "Tilemap");


    // Creating a shape that can be used

    // Jim the protaganist I guess
    sf::CircleShape mJim(16);
    mJim.setFillColor(sf::Color::Red);
    
    mJim = mJim;

   

    int xJim = 0;
    int yJim = 0;

    int stepcount = 0;

    // define the level with an array of tile indices

    sf::View view;
    view.setSize(512, 256);
    view.setCenter(m_window.getSize().x / 2.f, m_window.getSize().y / 2.f);



    // int trap = 0; I need to include these functions in main or else the function does not work

    int random = rand() % 128;
    // std::cout<<random;
    int mTrap = 0;

    std::string message = "You notice a strange tile on the ground, and touch it with a 5 foot pole,"
                          " \n you then fall into a pit press Space to escape ";

    Dialogue Orc("OpenSans-Regular.ttf", message, 0, 10);


    
            const int level[] =
            {
                4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                4, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 2, 4, 0, 0, 0,
                1, 1, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3,
                23, 1, 0, 4, 2, 3, 3, 3, 3, 13, 1, 1, 1, 4, 4, 4,
                4, 1, 1, 4, 3, 3, 60, 25, 4, 4, 1, 1, 1, 2, 4, 4,
                4, 4, 1, 4, 3, 4, 18, 2, 4, 4, 1, 1, 1, 1, 2, 4,
                2, 4, 1, 4, 3, 4, 2, 2, 2, 4, 1, 1, 1, 1, 1, 1,
                4, 4, 1, 4, 3, 2, 2, 2, 4, 4, 4, 4, 1, 1, 1, 1,
            };

    
    // create the tilemap from the level definition

    // Need to move this
    float gridLength = 32;
    float gridWidth = 32;
    float viewspeed = 1;
    MyTiles map1;

    if (!map1.load("rpg_textures.png", sf::Vector2u(gridLength, gridWidth), level, 16, 8))
    {
        std::cout<<"Error loading textures";
        exit(1);
    }

    mJim.setPosition(xJim, yJim);

    sf::RectangleShape Pause(sf::Vector2f(512, 256));
    Pause.setFillColor(sf::Color::Black);
    Pause.setPosition(0, 0);


        sf::Event event;

        playGame test;

    test.runGame(test,map1,Orc,70,xJim,yJim,m_window,mJim,mTrap,event,dtClock,stepcount,gridLength,gridWidth);

}


*/