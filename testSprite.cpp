/* commeningt this out while I work on my main. 

#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::Texture textureTile;
    textureTile.loadFromFile("IndianaJonesCanva.png");
    sf::Sprite prospector;
    prospector.setTexture(textureTile);
    // prospector.setTextureRect(sf::IntRect(550, 150, 475, 1400));
    prospector.setScale (0.25, 0.25);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(prospector);
        window.display();
    }
    return 0;
}
*/
