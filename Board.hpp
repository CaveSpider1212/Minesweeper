#pragma once

#include "Tile.hpp"

class Board
{
public:
	Board();
	~Board();
private:
	Tile* tiles[9][9]; // 9x9 board
};