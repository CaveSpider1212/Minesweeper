#pragma once

#include "Tile.hpp"

class BombTile : public Tile
{
public:
	BombTile(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Image& image);
};