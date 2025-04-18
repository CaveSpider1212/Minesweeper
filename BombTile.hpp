#pragma once

#include "Tile.hpp"

class BombTile : public Tile
{
public:
	BombTile(const sf::Vector2f& pos);

	void reveal(sf::RenderWindow& window);
	bool isBomb(void);
};