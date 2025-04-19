/*
4/12/25
PA 9
Minesweeper

Abby Wu Section 13 ID: 011912550
Aabhwan Adhikary Section 9 ID: 011915647
*/

#include <iostream>
#include "SFML/Graphics.hpp"

#include "Board.hpp"
#include "Tile.hpp"

int main(void)
{
	srand(time(nullptr));
	int windowSizeX = 40 + BOARD_SIZE * TILE_SIZE, windowSizeY = 100 + BOARD_SIZE * TILE_SIZE;

	sf::RenderWindow window(sf::VideoMode(sf::Vector2u(windowSizeX, windowSizeY)), "Minesweeper");
	Board gameBoard;

	while (window.isOpen()) {
		window.clear(sf::Color(100, 100, 100)); // changes window color to gray

		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		// testing
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			// add when mouse button goes up as well
			gameBoard.revealClickedTile(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, window);
		}

		gameBoard.draw(window); // program continuously updates/draws current game board on window
		window.display();
	}

	return 0;
}