#include "Board.hpp"

// created 4/15/2025
Board::Board(sf::RenderWindow& window)
{
	generateBoard(window);
}

// created 4/15/2025
Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			delete tiles[i][j];
		}
	}
}

// create 4/15/2025
void Board::generateBoard(sf::RenderWindow& window)
{
	int y = START_Y, rows = 0; // starting y-coordinate and outer array index

	while (rows < BOARD_SIZE) { // places tiles in each row, then moves to the next row
		int x = START_X, cols = 0; // starting x-coordinate and inner array index

		while (cols < BOARD_SIZE) { // places tiles horizontally
			tiles[rows][cols] = new Tile(sf::Vector2f(x, y));
			(tiles[rows][cols])->draw(window);
			cols++;
			x += TILE_SIZE;
		}

		rows++;
		y += TILE_SIZE;
	}
}
