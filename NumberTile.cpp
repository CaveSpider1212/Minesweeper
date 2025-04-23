#include "NumberTile.hpp"

// created 4/18/2025
// done
NumberTile::NumberTile(const sf::Vector2f& pos, int adjacentMines)
{
	isRevealed = false, flagged = false;
	startX = pos.x, startY = pos.y;
	endX = startX + TILE_SIZE, endY = startY + TILE_SIZE;
	this->adjacentMines = adjacentMines;

	this->setTexture(&Tile::coveredTileTexture);
	this->setPosition(pos);
	this->setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	this->setOutlineColor(sf::Color::Black);
	this->setOutlineThickness(2.0);
}

// created 4/18/2025
// done
void NumberTile::reveal(void)
{
	if (!isRevealed) { // if the tile is not already revealed yet
		isRevealed = true;
		
		switch (adjacentMines) {
		case 1:
			this->setTexture(&Tile::oneTileTexture);
			break;
		case 2:
			this->setTexture(&Tile::twoTileTexture);
			break;
		case 3:
			this->setTexture(&Tile::threeTileTexture);
			break;
		case 4:
			this->setTexture(&Tile::fourTileTexture);
			break;
		case 5:
			this->setTexture(&Tile::fiveTileTexture);
			break;
		case 6:
			this->setTexture(&Tile::sixTileTexture);
			break;
		case 7:
			this->setTexture(&Tile::sevenTileTexture);
			break;
		}
	}
}

// created 4/19/2025
// done
void NumberTile::flag(int *flagsRemaining)
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
bool NumberTile::isBomb(void)
{
	return false;
}

// created 4/18/2025
// done
bool NumberTile::isNumber(void)
{
	return true;
}

// created 4/18/2025
// done
bool NumberTile::isBlankTile(void)
{
	return false;
}
