#pragma once

#include <SFML/Graphics.hpp>

// TILE TEXTURES
const sf::Texture coveredTileTexture(sf::Image("Images/coveredTile.png"));


class Tile : public sf::RectangleShape
{
public:
	Tile(const sf::Vector2f& pos);

	void draw(sf::RenderWindow &window);
protected:
	bool isRevealed;
};
