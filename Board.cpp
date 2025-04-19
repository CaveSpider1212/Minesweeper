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
}

// created 4/17/2025
// done
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

			bombsPlaced++;
		}
	}
}

// created 4/18/2025
// done
void Board::placeNumberTiles(void)
{
	for (int i = 0; i < BOARD_SIZE; i++) { // i: rows of the tiles array
		for (int j = 0; j < BOARD_SIZE; j++) { // j: columns of the tiles array
			if (!tiles[i][j]->isBomb()) {
				int adjacentMines = countAdjacentBombs(j, i);

				if (adjacentMines != 0) {
					int startX = tiles[i][j]->getStartX(), startY = tiles[i][j]->getStartY();
					delete tiles[i][j];

					tiles[i][j] = new NumberTile(sf::Vector2f(startX, startY), adjacentMines);
					tiles[i][j]->reveal(); // !!!! REMOVE WHEN DONE TESTING
				}
			}
		}
	}
}

// created 4/17/2025
// done
void Board::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			tiles[i][j]->draw(window);
		}
	}
}

// created 4/17/2025
// done
void Board::revealClickedTile(int mouseX, int mouseY, sf::RenderWindow& window)
{
	for (int i = 0; i < BOARD_SIZE; i++) { // i: rows of tiles array
		for (int j = 0; j < BOARD_SIZE; j++) { // j: columns of tiles array
			if (mouseX >= tiles[i][j]->getStartX() && mouseX < tiles[i][j]->getEndX() &&
				mouseY >= tiles[i][j]->getStartY() && mouseY < tiles[i][j]->getEndY()) {
				// if the mouse's x and y coordinates are within the current tile's x and y coordinates
				tiles[i][j]->reveal();

				if (!firstTileClicked) { // places bombs and number tiles once the first tile is clicked
					firstTileClicked = true;
					fillBombOffLimitsArray(j, i);
					placeBombs();
					placeNumberTiles();
				}
			}
		}
	}
}

// created 4/17/2025
// done
void Board::fillBombOffLimitsArray(int centerCol, int centerRow)
{
	int minCol = centerCol - 1, minRow = centerRow - 1, maxCol = centerCol + 1, maxRow = centerRow + 1;

	// checks that the minimum and maximum column and row values are within the bounds of the array of tiles (i.e. not less than 0 and not greater than the board size)
	if (minRow < 0) {
		minRow = 0;
	}
	
	if (minCol <= 0) {
		minCol = 0;
	}

	if (maxRow >= BOARD_SIZE) {
		maxRow = BOARD_SIZE - 1;
	}

	if (maxCol >= BOARD_SIZE) {
		maxCol = BOARD_SIZE - 1;
	}

	int coords = 0, row = minRow, col = minCol;
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
// done
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

// created 4/18/2025
// done
int Board::countAdjacentBombs(int centerCol, int centerRow)
{
	int adjacentMines = 0;

	int minCol = centerCol - 1, minRow = centerRow - 1, maxCol = centerCol + 1, maxRow = centerRow + 1;

	// checks that the minimum and maximum column and row values are within the bounds of the array of tiles (i.e. not less than 0 and not greater than the board size)
	if (minRow < 0) {
		minRow = 0;
	}

	if (minCol <= 0) {
		minCol = 0;
	}

	if (maxRow >= BOARD_SIZE) {
		maxRow = BOARD_SIZE - 1;
	}

	if (maxCol >= BOARD_SIZE) {
		maxCol = BOARD_SIZE - 1;
	}

	int coords = 0, row = minRow, col = minCol;
	while (row <= maxRow) { // iterates through rows of the tiles array
		int col = minCol;

		while (col <= maxCol) { // iterates through columns of the tiles array
			if (tiles[row][col]->isBomb()) {
				adjacentMines++;
			}

			col++;
		}

		row++;
	}

	return adjacentMines;
}
