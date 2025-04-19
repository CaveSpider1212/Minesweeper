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
	if (!isRevealed) { // if the tile is not already revealed yet
		isRevealed = true;
		this->setTexture(&bombTileTexture);
	}
}

// created 4/19/2025
// done
void BombTile::flag(void)
{
	if (!isRevealed) {
		// only works on tiles that haven't been revealed yet

		if (!flagged) { // if the tile is not already flagged, then flag it
			this->setTexture(&flagTileTexture);
			flagged = true;
		}
		else { // if the tile is already flagged, then remove the flag
			this->setTexture(&coveredTileTexture);
			flagged = false;
		}
	}
}

// created 4/18/2025
// done
bool BombTile::isBomb(void)
{
	return true;
}

// created 4/18/2025
// done
bool BombTile::isNumber(void)
{
	return false;
}

// created 4/18/2025
// done
bool BombTile::isBlankTile(void)
{
	return false;
}
