#pragma once

#include "Tile.hpp"

class BlankTile : public Tile
{
public:
	BlankTile(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Image &image);
};