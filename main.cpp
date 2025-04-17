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

int main(void)
{
	sf::RenderWindow window(sf::VideoMode({ 540, 540 }), "Minesweeper");
	Board gameBoard(window);

	while (window.isOpen()) {
		window.clear(sf::Color(100, 100, 100)); // changes window color to gray

		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		// testing
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			// std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
			gameBoard.revealClickedTile(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, window);
			// system("pause");
		}

		gameBoard.draw(window);
		window.display();
	}

	return 0;
}