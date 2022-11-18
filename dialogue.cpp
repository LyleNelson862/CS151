#include "dialogue.h"



 void Dialogue :: loadText(std::string fontType,std::string Message,int xPos,int yPos)

{
  
    sf::Font font;

    if (!font.loadFromFile(fontType))
    {
        std::cout<<"Error loading font";
    }
    sf::Text text;

    text.setFont(font);

    text.setString(Message);

    text.setCharacterSize(10);

    text.setFillColor(sf::Color::White);

    text.setPosition(xPos,yPos);
    



}

void Dialogue::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_text, states);
}
