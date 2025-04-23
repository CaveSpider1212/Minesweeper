// created 4/15/2025

#pragma once

#include <SFML/Graphics.hpp>

#define TILE_SIZE 45 // size of each side of the tile in pixels


class Tile : public sf::RectangleShape
{
public:
	virtual void reveal(void) = 0;
	virtual void flag(int *flagsRemaining) = 0;
	virtual bool isBomb(void) = 0;
	virtual bool isNumber(void) = 0;
	virtual bool isBlankTile(void) = 0;

	void draw(sf::RenderWindow& window);

	bool revealed(void);
	bool isflagged(void);

	int getStartX();
	int getStartY();

	int getEndX();
	int getEndY();

	// added "static" to prevent textures from being copied to each of the derived classes, which creates issues in the test cases
	static sf::Texture coveredTileTexture;
	static sf::Texture blankTileTexture;
	static sf::Texture bombTileTexture;
	static sf::Texture oneTileTexture;
	static sf::Texture twoTileTexture;
	static sf::Texture threeTileTexture;
	static sf::Texture fourTileTexture;
	static sf::Texture fiveTileTexture;
	static sf::Texture sixTileTexture;
	static sf::Texture sevenTileTexture;
	static sf::Texture flagTileTexture;
protected:
	bool isRevealed, flagged;
	int startX, startY, endX, endY;
};
