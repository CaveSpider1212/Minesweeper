// created 4/17/2025

#include "BlankTile.hpp"

// created 4/17/2025
// done
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
void BlankTile::reveal(void)
{
	if (!isRevealed) {
		isRevealed = true;
		this->setTexture(&blankTileTexture);
	}
}

// created 4/18/2025
// done
bool BlankTile::isBomb(void)
{
	return false;
}

// created 4/18/2025
// done
bool BlankTile::isNumber(void)
{
	return false;
}

// created 4/18/2025
// done
bool BlankTile::isBlankTile(void)
{
	return true;
}

