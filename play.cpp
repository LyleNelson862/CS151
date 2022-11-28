#include "play.h"


playGame::playGame()
{
     srand(time(NULL));
     int random = rand() %128;
        

    const int level[] =
    {
        4,4,4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
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

        Dia1.setMessage("Suddenly out of nowhere, darkness envelops you as you are sucked into outer space,\n"
        " press the spacebar to escape");
        
        Dia1.StopJones(Dia1, place, tile, Jones.xPos, Jones.yPos, window, Jones, trap, m_event);
        Jones.mCharacter.setPosition(Jones.xPos, Jones.yPos);
        // End of while loops
    }
}