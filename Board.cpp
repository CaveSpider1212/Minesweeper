#include "Board.hpp"

Board::Board(sf::RenderWindow& window)
{
	generateBoard(window);
}

Board::~Board()
{

}

// create 4/15/2025
void Board::generateBoard(sf::RenderWindow& window)
{
	int y = 20, rows = 0; // starting y-coordinate and outer array index

	while (rows < 10) { // places tiles in each row, then moves to the next row
		int x = 20, cols = 0; // starting x-coordinate and inner array index

		while (cols < 10) { // places tiles horizontally
			tiles[rows][cols] = new Tile(sf::Vector2f(x, y));
			(tiles[rows][cols])->draw(window);
			cols++;
			x += 50;
		}

		rows++;
		y += 50;
	}
}
