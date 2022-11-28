#include "play.h"

/*
playGame::playGame()
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

    // sf::sprite jim(texture);
    // window.draw(sprite);

    m_Xpos = 0;
    m_Ypos = 0;

    int stepcount = 0;

    // define the level with an array of tile indices

    sf::View view;
    view.setSize(512, 256);
    view.setCenter(m_window.getSize().x / 2.f, m_window.getSize().y / 2.f);

    //sf::CircleShape Joe(40);
    //Joe.setFillColor(sf::Color::Blue);
    //Joe.setPosition(100, 100);

    // int trap = 0; I need to include these functions in main or else the function does not work

    int random = rand() % 128;
    // std::cout<<random;
    int mTrap = 0;

    std::string message = "You notice a strange tile on the ground, and touch it with a 5 foot pole,"
                          " \n you then fall into a pit press Space to escape ";


//    message = "An Orc with armed musket approaches you, and wants to speak with you "
  //            "\n Press T to speak the orc";

    //Dialogue Orc("OpenSans-Regular.ttf", message, 0, 10);


    
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

    mJim.setPosition(m_Xpos, m_Ypos);

    sf::RectangleShape Pause(sf::Vector2f(512, 256));
    Pause.setFillColor(sf::Color::Black);
    Pause.setPosition(0, 0);


        sf::Event event;
        m_event = event;
}

*/

//Old move function. 
/*
void playGame:: move(sf::RenderWindow &window, sf::Event &event, int &xPos, int &yPos, int gridSize, int &stepcount)
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
*/


/*
    void playGame::runGame(playGame &gameObj, MyTiles &MapObj, Dialogue &DiaObj,int tile,int xPos,int yPos,sf::RenderWindow &window,
    sf::CircleShape &jim,int &trap,sf::Event &event,sf::Clock dtClock,int stepcount,int gridLength,int gridWidth) //moved becuase it is a long line
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

             gameObj.move(window,event,xPos,yPos,gridLength,stepcount);



           }
       

        // Render the map and the game elements.
        window.clear();
        window.draw(MapObj);

        window.draw(jim);

        window.display();

        int place = MapObj.findTile(xPos, yPos, gridLength, gridWidth);

        DiaObj.Stop(DiaObj, place, 70, xPos, yPos, window, jim, trap, event);
        jim.setPosition(xPos, yPos);
        // End of while loops
    }
    }

*/
void playGame::runGameJones(MyTiles &MapObj, Dialogue &DiaObj, int tile, sf::RenderWindow &window,
                             Character &Jones, int &trap, sf::Event &event, sf::Clock dtClock, int stepcount, int gridLength, int gridWidth) // moved becuase it is a long line
{
    while (window.isOpen())
    {
        // Updating dt

        // dt = dtClock.restart().asSeconds();

        // handle events

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            Jones.moveJones(window, event, gridLength, stepcount);
        }

        // Render the map and the game elements.
        window.clear();
        window.draw(MapObj);

        window.draw(Jones.mCharacter);
        window.display();

        int place = MapObj.findTile(Jones.xPos, Jones.yPos, gridLength, gridWidth);
        DiaObj.StopJones(DiaObj, place, 70, Jones.xPos, Jones.yPos, window, Jones, trap, event);
        Jones.mCharacter.setPosition(Jones.xPos, Jones.yPos);
        // End of while loops
    }
}