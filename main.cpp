#include "game.h"

int main()
{


    //Placing a comment in here to check for pushing 
    
    // create the window

    sf::Clock dtClock;
    float dt = 0.f;
    //Clock used to help fix the input
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

    // Creating a shape that can be used

    //Jim the protaganist I guess
    sf::CircleShape jim(16);
    jim.setFillColor(sf::Color::Red);

    int xJim = 0;
    int yJim = 0;

    // define the level with an array of tile indices

    sf::View view;
    view.setSize(512,256);
    view.setCenter(window.getSize().x/2.f,window.getSize().y/2.f);


    
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

        float gridLength=32;
        float gridWidth =32;    
        float viewspeed =1;
    MyTiles map;
    if (!map.load("rpg_textures.png", sf::Vector2u(gridLength, gridWidth), level, 16, 8))
        return -1;

    // run the main loop
    while (window.isOpen())
    {

        //Updating dt

            dt = dtClock.restart().asSeconds(); 

        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Render the map and the game elements.
        window.clear();
        window.draw(map);

        jim.setPosition(xJim, yJim);
        window.draw(jim);
        window.display();



        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Right)
            {
                xJim=xJim+gridLength;
                usleep(9000);
                    if(xJim>512)
                    {
                        xJim=0;
                        yJim=0;
                    }
            }
            else if (event.key.code == sf::Keyboard::Left)
            {
                xJim=xJim-gridLength;
                usleep(9000);
                    if(xJim<0)
                    {
                        xJim=0;
                        yJim=0;
                    }
                
            }
             else if (event.key.code == sf::Keyboard::Down)
            {
                 yJim=yJim+gridWidth;
                usleep(9000);
                    if(yJim>256)
                    {
                        xJim=0;
                        yJim=0;
                    }
            }
             else if (event.key.code == sf::Keyboard::Up)
            {
                  yJim=yJim-gridWidth;
                usleep(9000);
                    if(yJim<0)
                    {
                        xJim=0;
                        yJim=0;
                    }
            }

        }


    //Tried to move the camera but it does not work.

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::D)
            {
                view.move(viewspeed*dt,0.f);
            }
            else if (event.key.code == sf::Keyboard::A)
            {
                view.move(-viewspeed * dt,0.f);
                
            }
             else if (event.key.code == sf::Keyboard::W)
            {
                 view.move(0.f,viewspeed * dt);

            }
             else if (event.key.code == sf::Keyboard::S)
            {
                 view.move(0.f,-viewspeed * dt);

            }

        }
        
        
        
    }

    return 0;
}
