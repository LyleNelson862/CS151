#include "game.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

    // Creating a shape that can be used

    sf::CircleShape jim(16);
    jim.setFillColor(sf::Color::Red);

    // sf::sprite jim(texture);
    // window.draw(sprite);

    int xJim = 0;
    int yJim = 0;

    // define the level with an array of tile indices
    
    const int level[] =
    {
        4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        4, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 2, 4, 0, 0, 0,
        1, 1, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3,
        23, 1, 0, 4, 2, 3, 3, 3, 3, 4, 1, 1, 1, 4, 4, 4,
        4, 1, 1, 4, 3, 3, 3, 4, 4, 4, 1, 1, 1, 2, 4, 4,
        4, 4, 1, 4, 3, 4, 2, 2, 4, 4, 1, 1, 1, 1, 2, 4,
        2, 4, 1, 4, 3, 4, 2, 2, 2, 4, 1, 1, 1, 1, 1, 1,
        4, 4, 1, 4, 3, 2, 2, 2, 4, 4, 4, 4, 1, 1, 1, 1,
    };

    // create the tilemap from the level definition
    MyTiles map;
    if (!map.load("rpg_textures.png", sf::Vector2u(32, 32), level, 16, 8))
        return -1;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // draw the map
        window.clear();
        window.draw(map);
        jim.setPosition(xJim, yJim);
        window.draw(jim);
        window.display();

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Right)
            {
                xJim++;
            }
            else if (event.key.code == sf::Keyboard::Left)
            {
                xJim--;
            }
             else if (event.key.code == sf::Keyboard::Down)
            {
                yJim++;
            }
             else if (event.key.code == sf::Keyboard::Up)
            {
                yJim--;
            }

        }
    }

    return 0;
}
