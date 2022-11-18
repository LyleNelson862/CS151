#include "dialogue.h"


Dialogue::Dialogue(std::string fontType,std::string message,int xPos, int yPos)
{
    sf::Font font;

     if (!font.loadFromFile(fontType))
    {
        std::cout<<"Error loading font";
        exit(2);
    }
    mFont = font;

    //mTest = message;
    mText.setFont(mFont);
    mText.setCharacterSize(10);
    mText.setString(message);
    mText.setFillColor(sf::Color::White);
    mText.setPosition(xPos,yPos);    
}


    void Dialogue:: Stop(const Dialogue &obj,int place,int tile,int xPos,int yPos,sf::RenderWindow &window,sf::CircleShape jim,int trap)

{
//Needs to accept a integer to see if function has already ran. 

 sf::RectangleShape Pause(sf::Vector2f(512,256));
    Pause.setFillColor(sf::Color::Black);
    Pause.setPosition(0,0);

     if(trap == 0 )
    {
        // needs to accept a spot
        if(place == tile)
        {
            //variable
             int cease2 =0;
             window.draw(Pause); // How do I allow the function to draw something to window.
             window.draw(obj); //Accepts dialogue would need to pass an object to itself
             window.display();

            do{
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) // Need to pass a key as a function.
                 {
                    cease2 =1; //
                    jim.setPosition(xPos,yPos);
                    trap++;
                    
                 }   
            
            }while(cease2 == 0);                    
    
        }
    }
}
    

void Dialogue::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mRect,states);
    target.draw(mText, states);
}
