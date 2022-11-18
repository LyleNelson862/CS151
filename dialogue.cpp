#include "dialogue.h"


Dialogue::Dialogue(std::string fontType,std::string message,int xPos, int yPos)
{
    sf::Font font;

     if (!font.loadFromFile(fontType))
    {
        std::cout<<"Error loading font";
        exit(2);
    }
    mTest = message;
    mText.setFont(mFont);
    mText.setCharacterSize(20);
    mText.setString(message);
    mText.setFillColor(mTextNormal);
    mText.setPosition(xPos,yPos);
    
}


void Dialogue::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_text, states);
}
