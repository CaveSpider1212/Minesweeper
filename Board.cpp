// created 4/15/2025

#include "Board.hpp"

// created 4/15/2025
// done
Board::Board(sf::RenderWindow& window)
{
	generateBoard();
}

// created 4/15/2025
// done
Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			delete tiles[i][j];
		}
	}
}

// create 4/15/2025
// done
void Board::generateBoard(void)
{
	int y = START_Y, rows = 0; // starting y-coordinate and outer array index

	while (rows < BOARD_SIZE) { // places tiles in each row, then moves to the next row
		int x = START_X, cols = 0; // starting x-coordinate and inner array index

		while (cols < BOARD_SIZE) { // places tiles horizontally
			tiles[rows][cols] = new BlankTile(sf::Vector2f(x, y));

			cols++;
			x += TILE_SIZE;
		}

		rows++;
		y += TILE_SIZE;
	}
}

// created 4/17/2025
void Board::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			tiles[i][j]->draw(window);
		}
	}
}

// created 4/17/2025
void Board::revealClickedTile(int mouseX, int mouseY, sf::RenderWindow& window)
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (mouseX >= tiles[i][j]->getStartX() && mouseX <= tiles[i][j]->getEndX() &&
				mouseY >= tiles[i][j]->getStartY() && mouseY <= tiles[i][j]->getEndY()) {
				tiles[i][j]->reveal(window);
			}
		}
	}
}
