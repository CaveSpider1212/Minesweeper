#pragma once

#define START_X 20 // starting x-coordinate of the board
#define START_Y 20 // starting y-coordinate of the board
#define BOARD_SIZE 10 // size of each side of the board (square)

#include "Tile.hpp"

class Board
{
public:
	Board(sf::RenderWindow& window);
	~Board();

	void generateBoard(sf::RenderWindow& window);
private:
	Tile* tiles[BOARD_SIZE][BOARD_SIZE]; // 9x9 board
};