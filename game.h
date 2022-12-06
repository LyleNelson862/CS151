#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
// #include <Sprite.hpp>
#include<ctime>
#include<unistd.h>
#include<iostream>


class MyTiles : public sf::Drawable, public sf::Transformable
{
public:
  
    bool load(const std::string &tileset, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height);
    int findTile(int xPosition, int yPosition, int tileLength,int tileWidth);


    

private:
    
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};





#endif