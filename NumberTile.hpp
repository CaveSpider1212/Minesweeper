#pragma once

#include "Tile.hpp"

class NumberTile : public Tile
{
public:
	NumberTile(const sf::Vector2f& pos, int adjacentMines);

	void reveal(void);
	void flag(void);
	bool isBomb(void);
	bool isNumber(void);
	bool isBlankTile(void);
private:
	int adjacentMines;
};