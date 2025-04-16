#pragma once

#define TILE_SIZE 50 // size of each side of the tile in pixels

#include <SFML/Graphics.hpp>

// TILE TEXTURES
const sf::Texture coveredTileTexture(sf::Image("Images/coveredTile.png"));


class Tile : public sf::RectangleShape
{
public:
	Tile(const sf::Vector2f& pos);

	void draw(sf::RenderWindow& window);
protected:
	bool isRevealed;
	int startX, startY, endX, endY;
};
