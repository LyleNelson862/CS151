#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <SFML/Graphics.hpp>
#include<ctime>
#include<unistd.h>
#include<iostream>
#include <string>

class Dialogue //: public sf::Drawable, public sf::Transformable 
{
    public:
        void loadText(std::string fontType,std::string Message,int xPos,int yPos);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        sf::Text m_text;

};


#endif