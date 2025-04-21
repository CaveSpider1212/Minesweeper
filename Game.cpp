// created 4/15/2025

#include "Game.hpp"

// created 4/15/2025
// done
Game::Game()
{
	firstTileClicked = false, gameOngoing = true, playerWon = false;
	generateBoard();
}

// created 4/15/2025
// done
Game::~Game()
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			delete tiles[i][j];
		}
	}
}

// create 4/15/2025
// done
void Game::generateBoard(void)
{
	placeBlankTiles();
}

// created 4/17/2025
// done
void Game::placeBlankTiles(void)
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
void Game::placeBombs(void)
{
	int bombsPlaced = 0;
	while (bombsPlaced < BOMB_COUNT) {
		int randCol = rand() % BOARD_SIZE, randRow = rand() % BOARD_SIZE;
		int randX = START_X + (randCol * TILE_SIZE), randY = START_Y + (randRow * TILE_SIZE);

		if (!tiles[randRow][randCol]->isBomb() && !coordsInOffLimitsArray(randCol, randRow)) {
			// if the randomly selected tile isn't already a bomb, then delete the current tile and create a new bomb tile at the same spot
			delete tiles[randRow][randCol];

			tiles[randRow][randCol] = new BombTile(sf::Vector2f(randX, randY));
			// tiles[randRow][randCol]->reveal(); // !!!! REMOVE WHEN DONE TESTING

			bombsPlaced++;
		}
	}
}

// created 4/18/2025
// done
void Game::placeNumberTiles(void)
{
	for (int i = 0; i < BOARD_SIZE; i++) { // i: rows of the tiles array
		for (int j = 0; j < BOARD_SIZE; j++) { // j: columns of the tiles array
			if (!tiles[i][j]->isBomb()) {
				int adjacentMines = countAdjacentBombs(j, i);

				if (adjacentMines != 0) {
					int startX = tiles[i][j]->getStartX(), startY = tiles[i][j]->getStartY();
					delete tiles[i][j];

					tiles[i][j] = new NumberTile(sf::Vector2f(startX, startY), adjacentMines);
					// tiles[i][j]->reveal(); // !!!! REMOVE WHEN DONE TESTING
				}
			}
		}
	}
}

// created 4/17/2025
// done
void Game::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			tiles[i][j]->draw(window);
		}
	}

}

// created 4/18/2025
void Game::recursivelyRevealTiles(int col, int row)
{
	tiles[row][col]->reveal();

	if (tiles[row][col]->isNumber()) { // base case for recursion; recursion ends when a number tile is reached and does nothing
		return;
	}
	else { // if the current tile is not a number, then reveal it and go to the next tile in all 4 directions

		// NEED TO CHECK IF TILE IS NOT ALREADY REVEALED!!!!
		// checks if the next column/row is within the bounds of the tiles array; continues recursion if it is
		if (col + 1 < BOARD_SIZE) {
			if (!tiles[row][col + 1]->revealed()) {
				// if the tile on the right is not already revealed, go to the right
				recursivelyRevealTiles(col + 1, row);
			}
		}
		if (col - 1 >= 0) {
			if (!tiles[row][col - 1]->revealed()) {
				// if the tile on the left is not already revealed, go to the left
				recursivelyRevealTiles(col - 1, row);
			}
		}
		if (row - 1 >= 0) {
			if (!tiles[row - 1][col]->revealed()) {
				// if the tile above is not already revealed, go up
				recursivelyRevealTiles(col, row - 1);
			}
		}
		if (row + 1 < BOARD_SIZE) {
			if (!tiles[row + 1][col]->revealed()) {
				// if the tile below is not already revealed, go down
				recursivelyRevealTiles(col, row + 1);
			}
		}
		if (col + 1 < BOARD_SIZE && row + 1 < BOARD_SIZE) {
			if (!tiles[row + 1][col + 1]->revealed()) {
				// if the tile to the bottom-right is not already revealed, go to the bottom-right
				recursivelyRevealTiles(col + 1, row + 1);
			}
		}
		if (col + 1 < BOARD_SIZE && row - 1 >= 0) {
			if (!tiles[row - 1][col + 1]->revealed()) {
				// if the tile to the top-right is not already revealed, go to the top-right
				recursivelyRevealTiles(col + 1, row - 1);
			}
		}
		if (col - 1 >= 0 && row + 1 < BOARD_SIZE) {
			if (!tiles[row + 1][col - 1]->revealed()) {
				// if the tile to the bottom-left is not already revealed, go to the bottom-left
				recursivelyRevealTiles(col - 1, row + 1);
			}
		}
		if (col - 1 >= 0 && row - 1 >= 0) {
			if (!tiles[row - 1][col - 1]->revealed()) {
				// if the tile to the top-left is not already revealed, go to the top-left
				recursivelyRevealTiles(col - 1, row - 1);
			}
		}
	}
}

// created 4/17/2025
// done
void Game::revealClickedTile(int mouseX, int mouseY)
{
	for (int i = 0; i < BOARD_SIZE; i++) { // i: rows of tiles array
		for (int j = 0; j < BOARD_SIZE; j++) { // j: columns of tiles array
			if (mouseX >= tiles[i][j]->getStartX() && mouseX < tiles[i][j]->getEndX() &&
				mouseY >= tiles[i][j]->getStartY() && mouseY < tiles[i][j]->getEndY()) {
				// if the mouse's x and y coordinates are within the current tile's x and y coordinates
				if (!tiles[i][j]->isflagged() && gameOngoing) { // if the tile is not already flagged and the game is still going (player hasn't won/lost yet), then reveal it
					tiles[i][j]->reveal();

					if (!firstTileClicked) { // places bombs and number tiles once the first tile is clicked
						firstTileClicked = true;
						fillBombOffLimitsArray(j, i);
						placeBombs();
						placeNumberTiles();
					}

					if (tiles[i][j]->isBlankTile()) { // if the clicked tile is a blank tile, then recursively reveal all adjacent blank tiles up to the number tiles
						recursivelyRevealTiles(j, i);
					}

					if (tiles[i][j]->isBomb()) { // if the clicked tile is a bomb, the game ends
						gameOngoing = false;
					}

					if (countUnrevealedTiles() == BOMB_COUNT) { 
						// if the number of unrevealed tiles is equal to the number of bombs (i.e. player has mined every tile that isn't a bomb), then the game ends and the player wins
						gameOngoing = false;
						playerWon = true;
					}
				}
			}
		}
	}
}

// created 4/19/2025
void Game::toggleFlagTile(int mouseX, int mouseY)
{
	for (int i = 0; i < BOARD_SIZE; i++) { // i: rows of tiles array
		for (int j = 0; j < BOARD_SIZE; j++) { // j: columns of tiles array
			if (mouseX >= tiles[i][j]->getStartX() && mouseX < tiles[i][j]->getEndX() &&
				mouseY >= tiles[i][j]->getStartY() && mouseY < tiles[i][j]->getEndY()) {
				if (gameOngoing) {
					// if the mouse's x and y coordinates are within the current tile's x and y coordinates and the game is still going (player hasn't won/lost yet), then flag or unflag the tile
					tiles[i][j]->flag();
				}
			}
		}
	}
}

// created 4/17/2025
// done
void Game::fillBombOffLimitsArray(int centerCol, int centerRow)
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
bool Game::coordsInOffLimitsArray(int col, int row)
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
int Game::countAdjacentBombs(int centerCol, int centerRow)
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

// created 4/19/2025
int Game::countUnrevealedTiles(void)
{
	int count = 0;

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (!tiles[i][j]->revealed()) {
				count++;
			}
		}
	}

	return count;
}

// created 4/19/2025
// done
bool Game::isGameOngoing(void)
{
	return gameOngoing;
}

// created 4/19/2025
// done
bool Game::didPlayerWin(void)
{
	return playerWon;
}


