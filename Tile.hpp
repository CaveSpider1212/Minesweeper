// created 4/15/2025

#pragma once

#include <SFML/Graphics.hpp>

#define TILE_SIZE 50 // size of each side of the tile in pixels

// TILE TEXTURES
const sf::Texture coveredTileTexture(sf::Image("Images/coveredTile.png"));
const sf::Texture blankTileTexture(sf::Image("Images/minesweeperTilesBlank.png"));
const sf::Texture bombTileTexture(sf::Image("Images/minesweeperTilesBomb.png"));


class Tile : public sf::RectangleShape
{
public:
	virtual void reveal(sf::RenderWindow& window) = 0;
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
