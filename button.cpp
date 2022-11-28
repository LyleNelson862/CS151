#include "button.h"

// Default constructor that loads texture from file “button.png” and font from “college.ttf” file.
// set texture for mButton, set the origin to the middle of the button (texture),
// set color to White, position to {300,100}, set state to normal, and scale to 100%
// set font for the text, set the size of the text to the half of Button size, set the origin to the middle of the text
// and set position at the middle of the button, assign “Push me!” as a string of the button
Button::Button()
{
    if (!mTexture.loadFromFile("button.png"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }
    mButton.setTexture(mTexture);

    // get size of image
    sf::Vector2u imageSize = mTexture.getSize();
    // change origing to the center of the image (maks rotation easy)
    mButton.setOrigin(imageSize.x / 2, imageSize.y / 2);
    // set position
    mPosition.x = 300;
    mPosition.y = 100;
    mBtnState = normal;

    mButton.setPosition(mPosition.x, mPosition.y);
    // choose color
    mButtonColor = sf::Color::White;
    mButton.setColor(mButtonColor);
    // set size as a ration of original size
    mButton.setScale(1, 1);

    mTextNormal = sf::Color(0, 250, 0); // sf::Color::Green;
    mTextHover = sf::Color::Red;

    // Make lable
    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout << "Error opening file\n";
        exit(2);
    }
    mText.setFont(mFont);
    // choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height / 2;
    mText.setCharacterSize(fontSize);
    // set lable
    mText.setString("Push me!");
    // set origing to the middle
    mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);
    // set position at the midle of the button
    mText.setPosition(imageSize.x / 2, imageSize.y / 2);
    // choose colors
    mText.setFillColor(mTextNormal);
}

Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{

    if (!mTexture.loadFromFile("button.png"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }
    // creat sprite that look like a button
    mButton.setTexture(mTexture);

    // get size of image
    sf::Vector2u imageSize = mTexture.getSize();
    // change origing to the center of the image (maks rotation easy)
    mButton.setOrigin(imageSize.x / 2, imageSize.y / 2);
    // set position
    mPosition = position;
    mButton.setPosition(mPosition.x, mPosition.y);
    // choose color
    mButtonColor = color;
    mButton.setColor(mButtonColor);
    // set size as a ration of original size
    mButton.setScale(size.x / imageSize.x, size.y / imageSize.y);
    mBtnState = normal;

    mTextNormal = sf::Color(0, 250, 0); // sf::Color::Green;
    mTextHover = sf::Color::Blue;
    // Make lable
    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout << "Error opening file\n";
        exit(2);
    }

    // sf::Text mText;
    mText.setFont(mFont);
    // choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height / 2;
    mText.setCharacterSize(fontSize);
    // set lable
    mText.setString(s);
    // set origing to the middle
    mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);
    // set position at the midle of the button
    mText.setPosition(position.x, position.y - fontSize / 4);
    // choose colors

    mText.setFillColor(mTextNormal);
}

void Button::update(sf::Event &e, sf::RenderWindow &window)
{
    // get position of the mouse
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    bool mouseInButton = mousePosition.x >= mButton.getPosition().x - mButton.getGlobalBounds().width / 2 && mousePosition.x <= mButton.getPosition().x + mButton.getGlobalBounds().width / 2 && mousePosition.y >= mButton.getPosition().y - mButton.getGlobalBounds().height / 2 && mousePosition.y <= mButton.getPosition().y + mButton.getGlobalBounds().height / 2;
    if (e.type == sf::Event::MouseMoved)
    {
        if (mouseInButton)
        {
            //std::cout<<"Mouse on button.";

            mText.setFillColor(mTextHover);
            mBtnState == state::hovered;
        }
        else
        {
            mText.setFillColor(mTextNormal);
            mBtnState = state::normal;
        }
    }
    if (e.type == sf::Event::MouseButtonPressed)
    {
        if (e.mouseButton.button == sf::Mouse::Left)
        {
            if (mouseInButton)
            {
                mButton.setRotation(180);
                mBtnState = state::clicked;
                //std::cout<<"Button clicked";
            }
            else
            {
                mButton.setRotation(0);
                mBtnState = state::normal;
            }
        }
    }
    if (e.type == sf::Event::MouseButtonReleased)
    {
        if (e.mouseButton.button == sf::Mouse::Left)
        {
            if (mouseInButton)
            {
                mText.setFillColor(mTextHover);
                mButton.setRotation(0);
                mBtnState = state::hovered;
            }
            else
            {
                mText.setFillColor(mTextNormal);
                mButton.setRotation(0);
                mBtnState = state::normal;
            }
        }
    }
}
void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mButton, states);
    target.draw(mText, states);
}

void Button::setPosition(sf::Vector2f position)
{
    mButton.setPosition(position);
        mText.setPosition(position.x,position.y -mButton.getGlobalBounds().height/20);

}
// change button size to size (what else needs to be changed?)
void Button::setSize(sf::Vector2f size)
{
    sf::Vector2u imageSize = mTexture.getSize();

    mButton.setScale(size.x / imageSize.x, size.y / imageSize.y);
    unsigned int fontSize = mButton.getGlobalBounds().height / 2;
    mText.setCharacterSize(fontSize);
    mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);

}

// change button color to color (what else needs to be changed?)
void Button::setColor(sf::Color btnColor)
{
    mButton.setColor(btnColor);
}
// change button label to s (what else needs to be changed?)
void Button::setText(std::string s)
{
    mText.setString(s);
}
  