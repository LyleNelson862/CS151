#include "game.h"
#include "dialogue.h"

int main()
{
     srand(time(NULL));

    // Placing a comment in here to check for pushing

    // create the window

    sf::Clock dtClock;
    float dt = 0.f;
    // Clock used to help fix the input
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

    // Creating a shape that can be used

    // Jim the protaganist I guess
    sf::CircleShape jim(16);
    jim.setFillColor(sf::Color::Red);

    // sf::sprite jim(texture);
    // window.draw(sprite);

    int xJim = 0;
    int yJim = 0;

    int stepcount = 0;

    // define the level with an array of tile indices

    sf::View view;
    view.setSize(512, 256);
    view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);

    sf::CircleShape Joe(40);
    Joe.setFillColor(sf::Color::Blue);
    Joe.setPosition(100, 100);

     //int trap = 0; I need to include these functions in main or else the function does not work 

     int random = rand() %128;
     //std::cout<<random;
    int trap2 = 0;

    std::string message = "You notice a strange tile on the ground, and touch it with a 5 foot pole,"
                          " \n you then fall into a pit press Space to escape ";

    Dialogue pit("OpenSans-Regular.ttf", message, 0, 0);

    message = "An Orc with armed musket approaches you, and wants to speak with you "
              "\n Press T to speak the orc";

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
    MyTiles map;

    if (!map.load("rpg_textures.png", sf::Vector2u(gridLength, gridWidth), level, 16, 8))
        return -1;

    jim.setPosition(xJim, yJim);

    sf::RectangleShape Pause(sf::Vector2f(512, 256));
    Pause.setFillColor(sf::Color::Black);
    Pause.setPosition(0, 0);

    // run the main loop
    while (window.isOpen())
    {
        // Updating dt

        dt = dtClock.restart().asSeconds();

        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Right)
                {
                    if (xJim < 480)
                    {
                        xJim = xJim + gridLength;
                        usleep(9000);
                        stepcount++;
                    }
                }
                else if (event.key.code == sf::Keyboard::Left)
                {
                    if (xJim > 0)
                    {
                        xJim = xJim - gridLength;
                        usleep(9000);
                        stepcount++;
                    }
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    if (yJim < 224)
                    {
                        yJim = yJim + gridWidth;
                        usleep(9000);

                        stepcount++;
                    }
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    if (yJim > 0)
                    {
                        yJim = yJim - gridWidth;
                        usleep(9000);

                        stepcount++;
                    }
                }
            }
        }

        // Render the map and the game elements.
        window.clear();
        window.draw(map);

        window.draw(jim);
        window.display();

        int place = map.findTile(xJim, yJim, gridLength, gridWidth);

        jim.setPosition(xJim, yJim);

        pit.Stop(pit, place, random, xJim, yJim, window, jim, trap2);
        
        //End of while loops
    }

    int place = map.findTile(xJim, yJim, gridLength, gridWidth);
    std::cout << "You just took " << stepcount << " steps\n";
    std::cout << "You ended on tile number " << place;

    return 0;
}
