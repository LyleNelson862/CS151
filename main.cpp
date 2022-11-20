#include "game.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

    // Creating a shape that can be used
    // sf::CircleShape jim(16);
    // jim.setFillColor(sf::Color::Red);

    // sf::RenderWindow character(sf::VideoMode(800, 800), "SFML works!");
    sf::Texture textureTile;
    textureTile.loadFromFile("IndianaJonesCanva.png");
    sf::Sprite jones;
    jones.setTexture(textureTile);
    jones.setScale (0.1, 0.1);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(jones);
        window.display();

    int xJones = 0;
    int yJones = 0;

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
        jones.setPosition(xJones, yJones);
        window.draw(jones);
        window.display();

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Right)
            {
                xJones++;
            }
            else if (event.key.code == sf::Keyboard::Left)
            {
                xJones--;
            }
             else if (event.key.code == sf::Keyboard::Down)
            {
                yJones++;
            }
             else if (event.key.code == sf::Keyboard::Up)
            {
                yJones--;
            }

        }
    }

    return 0;
    }
}
