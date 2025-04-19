// created 4/15/2025

#pragma once

#define START_X 20 // starting x-coordinate of the board
#define START_Y 120 // starting y-coordinate of the board
#define BOARD_SIZE 16 // size of each side of the square board
#define BOMB_COUNT 40

#include "Tile.hpp"
#include "BlankTile.hpp"
#include "BombTile.hpp"
#include "NumberTile.hpp"

#include <iostream>

class Board
{
public:
	Board();
	~Board();

	void generateBoard(void);

	void placeBlankTiles(void);
	void placeBombs(void);
	void placeNumberTiles(void);

	void draw(sf::RenderWindow& window);
	void recursivelyRevealTiles(int col, int row);

	void revealClickedTile(int mouseX, int mouseY);
	void toggleFlagTile(int mouseX, int mouseY);

	void fillBombOffLimitsArray(int centerCol, int centerRow);
	bool coordsInOffLimitsArray(int col, int row);
	int countAdjacentBombs(int centerCol, int centerRow);

	bool isGameOngoing(void);
	bool didPlayerWin(void);
private:
	Tile* tiles[BOARD_SIZE][BOARD_SIZE]; // 9x9 board
	bool firstTileClicked, gameOngoing, playerWon;
	int bombOffLimits[9][2]; // tiles that the bombs cannot be in (the surrounding tiles around the first clicked tile)
};