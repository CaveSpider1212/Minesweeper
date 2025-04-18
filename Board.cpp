// created 4/15/2025

#include "Board.hpp"

// created 4/15/2025
// done
Board::Board()
{
	firstTileClicked = false;
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
	placeBlankTiles();
	// placeBombs();
}

// created 4/17/2025
void Board::placeBlankTiles(void)
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

// created 4/18/2025
// done
void Board::placeBombs(void)
{
	int bombsPlaced = 0;
	while (bombsPlaced <= BOMB_COUNT) {
		int randCol = rand() % BOARD_SIZE, randRow = rand() % BOARD_SIZE;
		int randX = START_X + (randCol * TILE_SIZE), randY = START_Y + (randRow * TILE_SIZE);

		if (!tiles[randCol][randRow]->isBomb() && !coordsInOffLimitsArray(randCol, randRow)) {
			// if the randomly selected tile isn't already a bomb, then delete the current tile and create a new bomb tile at the same spot
			delete tiles[randRow][randCol];

			tiles[randRow][randCol] = new BombTile(sf::Vector2f(randX, randY));
			tiles[randRow][randCol]->reveal(); // !!!! REMOVE WHEN DONE TESTING
			// tiles[randRow][randCol]->draw(window);

			bombsPlaced++;
		}
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
	for (int i = 0; i < BOARD_SIZE; i++) { // rows of tiles array
		for (int j = 0; j < BOARD_SIZE; j++) { // columns of tiles array
			if (mouseX >= tiles[i][j]->getStartX() && mouseX < tiles[i][j]->getEndX() &&
				mouseY >= tiles[i][j]->getStartY() && mouseY < tiles[i][j]->getEndY()) {
				// if the mouse's x and y coordinates are within the current tile's x and y coordinates
				tiles[i][j]->reveal();

				if (!firstTileClicked) {
					fillBombOffLimitsArray(j, i); // !!!!! FIX THIS
					firstTileClicked = true;

					placeBombs();
				}
			}
		}
	}
}

// created 4/17/2025
void Board::fillBombOffLimitsArray(int centerCol, int centerRow)
{
	int minCol = centerCol - 1, minRow = centerRow - 1, maxCol = centerCol + 1, maxRow = centerRow + 1;
	
	int row = minRow, coords = 0;
	while (row <= maxRow) {
		int col = minCol;

		while (col <= maxCol) {
			bombOffLimits[coords][0] = col;
			bombOffLimits[coords][1] = row;
			
			col++;
			coords++;
		}

		row++;
	}
}

// created 4/18/2025
bool Board::coordsInOffLimitsArray(int col, int row)
{
	bool inArray = false;

	for (int i = 0; i < 9; i++) {
		if (bombOffLimits[i][0] == col && bombOffLimits[i][1] == row) {
			inArray = true;
			break;
		}
	}

	return inArray;
}

