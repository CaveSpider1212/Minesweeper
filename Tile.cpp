#include "Tile.hpp"

// created 4/15/2025
Tile::Tile(const sf::Vector2f& pos)
{
	isRevealed = false;

	this->setTexture(&coveredTileTexture);
	this->setPosition(pos);
	this->setSize({ 50, 50 });
	this->setOutlineColor(sf::Color::Black);
	this->setOutlineThickness(2.0);
}

// created 4/15/2025
void Tile::draw(sf::RenderWindow& window)
{
	window.draw(*this);
}
