#include "dialogue.h"

Dialogue::Dialogue(std::string fontType, std::string message, int xPos, int yPos)
{
    sf::Font font;

    if (!font.loadFromFile(fontType))
    {
        std::cout << "Error loading font";
        exit(2);
    }
    mFont = font;

    // mTest = message;
    mText.setFont(mFont);
    mText.setCharacterSize(10);
    mText.setString(message);
    mText.setFillColor(sf::Color::White);
    mText.setPosition(xPos, yPos);
}

void Dialogue::Stop(const Dialogue &obj, int place, int tile, int xPos, int yPos, sf::RenderWindow &window, sf::CircleShape &jim, int &trap, sf::Event &event)
{
    // Needs to accept a integer to see if function has already ran.

    sf::RectangleShape Pause(sf::Vector2f(512, 256));
    Pause.setFillColor(sf::Color::Black);
    Pause.setPosition(0, 0);

    // int exit=trap;
    // std::cout <<exit;
    if (trap == 0)
    {
        // needs to accept a spot
        if (place == tile)
        {

            // variable
            int cease = 0;
            window.draw(Pause); // How do I allow the function to draw something to window.
            window.draw(obj);   // Accepts dialogue would need to pass an object to itself
            Button Option("testing", {100, 100}, {50, 20}, sf::Color::Red);
            window.draw(Option);
            window.display();
            Option.update(event, window);

            while (cease == 0)
            {
                while (window.pollEvent(event))
                {
                    Option.update(event, window);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) // Need to pass a key as a function.
                    {
                        trap = -1;
                        // std::cout<<trap;
                        jim.setPosition(xPos, yPos);
                        jim.setFillColor(sf::Color::Blue);
                        cease = 1;
                        std::cout << "Can this be confirmed";
                    }
                }
            }
        }
    }
}

void Dialogue::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mRect, states);
    target.draw(mText, states);
}
