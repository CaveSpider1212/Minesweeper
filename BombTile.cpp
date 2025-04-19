#include "BombTile.hpp"

// created 4/18/2025
// done
BombTile::BombTile(const sf::Vector2f& pos)
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

// created 4/18/2025
// done
void BombTile::reveal(void)
{
	if (!isRevealed) {
		isRevealed = true;
		this->setTexture(&bombTileTexture);
	}
}

// created 4/18/2025
// done
bool BombTile::isBomb(void)
{
	return true;
}
