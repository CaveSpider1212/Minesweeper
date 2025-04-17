// created 4/15/2025

#pragma once

#define TILE_SIZE 50 // size of each side of the tile in pixels

#include <SFML/Graphics.hpp>

// TILE TEXTURES
const sf::Texture coveredTileTexture(sf::Image("Images/coveredTile.png"));
const sf::Texture blankTileTexture(sf::Image("Images/minesweeperTilesBlank.png"));


class Tile : public sf::RectangleShape
{
public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void reveal(sf::RenderWindow& window) = 0;

	int getStartX();
	int getStartY();

	int getEndX();
	int getEndY();
protected:
	bool isRevealed;
	int startX, startY, endX, endY;
};
