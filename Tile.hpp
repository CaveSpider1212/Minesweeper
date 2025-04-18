// created 4/15/2025

#pragma once

#include <SFML/Graphics.hpp>

#define TILE_SIZE 45 // size of each side of the tile in pixels

// TILE TEXTURES
const sf::Texture coveredTileTexture(sf::Image("Images/coveredTile.png"));
const sf::Texture blankTileTexture(sf::Image("Images/minesweeperTilesBlank.png"));
const sf::Texture bombTileTexture(sf::Image("Images/minesweeperTilesBomb.png"));
const sf::Texture oneTileTexture(sf::Image("Images/minesweeperTiles1.png"));
const sf::Texture twoTileTexture(sf::Image("Images/minesweeperTiles2.png"));
const sf::Texture threeTileTexture(sf::Image("Images/minesweeperTiles3.png"));
const sf::Texture fourTileTexture(sf::Image("Images/minesweeperTiles4.png"));
const sf::Texture fiveTileTexture(sf::Image("Images/minesweeperTiles5.png"));
const sf::Texture sixTileTexture(sf::Image("Images/minesweeperTiles6.png"));
const sf::Texture sevenTileTexture(sf::Image("Images/minesweeperTiles7.png"));


class Tile : public sf::RectangleShape
{
public:
	virtual void reveal(void) = 0;
	virtual bool isBomb(void) = 0;

	void draw(sf::RenderWindow& window);

	int getStartX();
	int getStartY();

	int getEndX();
	int getEndY();
protected:
	bool isRevealed;
	int startX, startY, endX, endY;
};
