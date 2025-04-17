// created 4/17/2025

#include "BlankTile.hpp"

// created 4/17/2025
// probably done
BlankTile::BlankTile(const sf::Vector2f& pos)
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

// created 4/17/2025
// done
void BlankTile::draw(sf::RenderWindow& window)
{
	window.draw(*this);
}

// created 4/17/2025
// done
void BlankTile::reveal(sf::RenderWindow& window)
{
	if (!isRevealed) {
		isRevealed = true;
		this->setTexture(&blankTileTexture);
	}

	this->draw(window);
}

