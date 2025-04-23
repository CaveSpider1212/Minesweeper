// created 4/17/2025

#include "BlankTile.hpp"

// created 4/17/2025
// done
BlankTile::BlankTile(const sf::Vector2f& pos)
{
	isRevealed = false, flagged = false;
	startX = pos.x, startY = pos.y;
	endX = startX + TILE_SIZE, endY = startY + TILE_SIZE;

	this->setTexture(&Tile::coveredTileTexture);
	this->setPosition(pos);
	this->setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	this->setOutlineColor(sf::Color::Black);
	this->setOutlineThickness(2.0);
}

// created 4/17/2025
// done
void BlankTile::reveal(void)
{
	if (!isRevealed) { // if the tile is not already revealed yet
		isRevealed = true;
		this->setTexture(&Tile::blankTileTexture);
	}
}

// created 4/19/2025
// done
void BlankTile::flag(int *flagsRemaining)
{
	if (!isRevealed) { 
		// only works on tiles that haven't been revealed yet

		if (!flagged) { // if the tile is not already flagged, then flag it
			if (*flagsRemaining > 0) {
				this->setTexture(&Tile::flagTileTexture);
				flagged = true;
				(*flagsRemaining)--;
			}
		}
		else { // if the tile is already flagged, then remove the flag
			this->setTexture(&Tile::coveredTileTexture);
			flagged = false;
			(*flagsRemaining)++;
		}
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

