// created 4/15/2025

#pragma once

#include "Tile.hpp"

class BlankTile : public Tile
{
public:
	BlankTile(const sf::Vector2f& pos);

	void draw(sf::RenderWindow& window);
	void reveal(sf::RenderWindow& window);
};