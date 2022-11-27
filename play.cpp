#include "play.h"
playGame::playGame()
{   
}
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
