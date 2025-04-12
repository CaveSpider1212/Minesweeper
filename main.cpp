/*
4/12/25
PA 9
Minesweeper

Abby Wu Section 13 ID: 011912550
Aabhwan Adhikary Section 9 ID: 011915647
*/

#include <iostream>
#include "SFML/Graphics.hpp"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode({ 540, 540 }), "Minesweeper");

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}
	}

	return 0;
}