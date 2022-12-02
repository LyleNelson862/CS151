#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
// #include <Sprite.hpp>
#include<ctime>
#include<unistd.h>
#include<iostream>

/*
int saveTile(int xPosition,int yPosition)
{
    int array[1];
    for(int i =0; i < 2; i++)
    {

    }
}

*/
class MyTiles : public sf::Drawable, public sf::Transformable
{
public:
  
    bool load(const std::string &tileset, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height);
    int findTile(int xPosition, int yPosition, int tileLength,int tileWidth);

        //void GetTile
    // Need to accept the array and x position of the shape 
    

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};





#endif