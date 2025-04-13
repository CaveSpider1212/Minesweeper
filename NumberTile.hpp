#pragma once

#include "Tile.hpp"

class NumberTile : public Tile
{
public:
	NumberTile(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Image& image);
};