#include "dialogue.h"

Dialogue::Dialogue()
{
    sf::Font font;

    if (!font.loadFromFile("OpenSans-Regular.ttf"))
    {
        std::cout << "Error loading font";
        exit(2);
    }
    mFont = font;

    // mTest = message;
    mText.setFont(mFont);
    mText.setCharacterSize(10);
    message = "Default message";
    mText.setString(message);
    mText.setFillColor(sf::Color::White);
    mText.setPosition(0, 0);
}

Dialogue::Dialogue(std::string fontType, std::string InputMessage, int xPos, int yPos)
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
    message = InputMessage;
    mText.setString(message);
    mText.setFillColor(sf::Color::White);
    mText.setPosition(xPos, yPos);
}

void Dialogue::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mRect, states);
    target.draw(mText, states);
}

void Dialogue::StopJones(const Dialogue &obj, int place, int tile, int xPos, int yPos, sf::RenderWindow &window, Character &jones, int &trap, sf::Event &event)
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

            // Button Option("Enter", {100, 100}, {50, 20}, sf::Color::Red);

            sf::Vector2f optionPos;
            optionPos.x = 100;
            optionPos.y = 100;
            sf::Vector2f optionSize;
            optionSize.x = 50;
            optionSize.y = 20;
            Button Option("Enter", optionPos, optionSize, sf::Color::Red);

            window.draw(Option);
            window.display();

            while (cease == 0)
            {
                while (window.pollEvent(event))
                {
                    Option.update(event, window);
                    window.draw(Option);
                    window.display();
                    usleep(1000);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) // Need to pass a key as a function.
                    {
                        trap = -1;
                        // std::cout<<trap;
                        jones.setPosition(xPos, yPos);
                        cease = 1;
                    }
                }
            }
        }
    }
}

    void Dialogue::setMessage(std::string m)
    {
        message = m;
        mText.setString(message);
    }
