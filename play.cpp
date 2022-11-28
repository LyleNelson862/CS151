#include "play.h"


playGame::playGame()
{
     srand(time(NULL));
     int random = rand() %128;
        

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

    
    if (!MapObj.load("rpg_textures.png", sf::Vector2u(MapObj.gridLength, MapObj.gridWidth), level, 16, 8))
    {
        std::cout<<"Error loading map";
        exit(1);
    }

}


void playGame::runGameJones(int tile, sf::RenderWindow &window,int &trap,sf::Clock dtClock, int stepcount) // moved becuase it is a long line
{
    while (window.isOpen())
    {
        // Updating dt

        // dt = dtClock.restart().asSeconds();

        // handle events

        while (window.pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Closed)
            {
                window.close();
            }

            Jones.moveJones(window, m_event, MapObj.gridLength, stepcount);
        }

        // Render the map and the game elements.
        window.clear();
        window.draw(MapObj);

        window.draw(Jones.mCharacter);
        window.display();

        int place = MapObj.findTile(Jones.xPos, Jones.yPos, MapObj.gridLength, MapObj.gridWidth);
        Dia1.StopJones(Dia1, place, 70, Jones.xPos, Jones.yPos, window, Jones, trap, m_event);
        Jones.mCharacter.setPosition(Jones.xPos, Jones.yPos);
        // End of while loops
    }
}