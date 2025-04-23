/*
4/12/25
PA 9
Minesweeper

Abby Wu Section 13 ID: 011912550
Aabhwan Adhikary Section 9 ID: 011915647
*/

#include <iostream>
#include "SFML/Graphics.hpp"

#include "Game.hpp"
#include "Tile.hpp"
#include "Test.hpp"

int main(void)
{
	srand(time(nullptr));
	int windowSizeX = 40 + BOARD_SIZE * TILE_SIZE, windowSizeY = 200 + BOARD_SIZE * TILE_SIZE;

	sf::RenderWindow window(sf::VideoMode(sf::Vector2u(windowSizeX, windowSizeY)), "Minesweeper");
	sf::Font textFont(std::filesystem::path("Fonts/Copeland.otf")); // font of the lose/win message shown on the window (can change if needed)

	Game game;

	while (window.isOpen()) {
		window.clear(sf::Color(100, 100, 100)); // changes window color to gray

		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}

			if (event->is<sf::Event::MouseButtonPressed>()) { // checks if any mouse button is pressed

				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) { // if it was the left mouse button that was pressed, then reveal the clicked tile
					game.revealClickedTile(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
					game.toggleFlagTile(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
				}
			}
		}

		game.draw(window); // program continuously updates/draws current game board on window

		sf::Texture gameTitleTexture(sf::Image("Images/Title.png"));
		sf::RectangleShape gameTitleShape({ 450, 150 });
		gameTitleShape.setTexture(&gameTitleTexture);
		gameTitleShape.setPosition({ 150, -40 });
		window.draw(gameTitleShape);

		sf::Text flagsRemainingText(textFont, "Flags remaining: " + std::to_string(game.getFlagsRemaining()));
		flagsRemainingText.setPosition({ 280, 100 });
		flagsRemainingText.setCharacterSize(20);
		flagsRemainingText.setFillColor(sf::Color::White);
		window.draw(flagsRemainingText);

		if (!game.isGameOngoing()) { // if the game is not going and the player did not win (if they lost), then print the lose text

			if (game.didPlayerWin()) { // if the player won, then print the win text
				sf::Text winText(textFont, "You won! Restart the application to play again.");
				winText.setPosition({ 180, 875 });
				winText.setCharacterSize(20);
				winText.setFillColor(sf::Color::Green);
				window.draw(winText);
			}
			else { // if the player lost, print the lose text
				sf::Text loseText(textFont, "You lost! Restart the application to play again.");
				loseText.setPosition({ 180, 875 });
				loseText.setCharacterSize(20);
				loseText.setFillColor(sf::Color::Red);
				window.draw(loseText);
			}
		}

		window.display();
	}

	Test t;

	return 0;
}