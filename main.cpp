#include "game.h"
#include "dialogue.h"

int main()
{

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

    int xJim = 0;
    int yJim = 0;

    int stepcount = 0;

    // define the level with an array of tile indices

    sf::View view;
    view.setSize(512, 256);
    view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);

    sf::RectangleShape Stop(sf::Vector2f(512,256));
    Stop.setFillColor(sf::Color::Black);
    Stop.setPosition(0,0);

    
    sf::CircleShape Joe(40);
    Joe.setFillColor(sf::Color::Blue);
    Joe.setPosition(100,100);


    int trap = 0;

    Dialogue pit("OpenSans-Regular.ttf","You have fallen in a pit press Space to escape",0,0);

    std::cout<<pit.mTest;


   
    

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
        }

        // Render the map and the game elements.
        window.clear();
        window.draw(map);

        window.draw(jim);
        window.display();

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

      


        
        int place = map.findTile(xJim, yJim, gridLength, gridWidth);

            jim.setPosition(xJim, yJim);





    //Make this into a function that allows you to enter an area 
    
    if(trap ==0 )
    {
        if(place == 70)
        {
             int cease =0;
             window.draw(Stop);
             window.draw(Joe);
             //window.draw(pit); 
             window.display();

            do{
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
                 {
                    cease =1;
                    jim.setPosition(xJim,yJim);
                    trap++;
                 }   
            
            }while(cease == 0);                    
    
        }
    

    }


    // End of While Loop 
    }





    int place = map.findTile(xJim, yJim, gridLength, gridWidth);
    std::cout << "You just took " << stepcount << " steps\n";
    std::cout << "You ended on tile number " << place;

    return 0;
}

// What I want

// Save the location of the circle
// Clear the Screen to black
//  Draw something new on this screen until
// Redraw the game a
