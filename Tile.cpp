#include "Tile.hpp"

// created 4/15/2025
Tile::Tile(const sf::Vector2f& pos)
{
	isRevealed = false;
	startX = pos.x, startY = pos.y;
	endX = startX + TILE_SIZE, endY = startY + TILE_SIZE;

	this->setTexture(&coveredTileTexture);
	this->setPosition(pos);
	this->setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	this->setOutlineColor(sf::Color::Black);
	this->setOutlineThickness(2.0);
}

// created 4/15/2025
void Tile::draw(sf::RenderWindow& window)
{
	window.draw(*this);
}
