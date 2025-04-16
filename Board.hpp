#pragma once

#include "Tile.hpp"

class Board
{
public:
	Board(sf::RenderWindow& window);
	~Board();

	void generateBoard(sf::RenderWindow& window);
private:
	Tile* tiles[10][10]; // 9x9 board
};