#include "NumberTile.hpp"

// created 4/18/2025
// done
NumberTile::NumberTile(const sf::Vector2f& pos, int adjacentMines)
{
	isRevealed = false;
	startX = pos.x, startY = pos.y;
	endX = startX + TILE_SIZE, endY = startY + TILE_SIZE;
	this->adjacentMines = adjacentMines;

	this->setTexture(&coveredTileTexture);
	this->setPosition(pos);
	this->setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	this->setOutlineColor(sf::Color::Black);
	this->setOutlineThickness(2.0);
}

// created 4/18/2025
// done
void NumberTile::reveal(void)
{
	if (!isRevealed) {
		isRevealed = true;
		
		switch (adjacentMines) {
		case 1:
			this->setTexture(&oneTileTexture);
			break;
		case 2:
			this->setTexture(&twoTileTexture);
			break;
		case 3:
			this->setTexture(&threeTileTexture);
			break;
		case 4:
			this->setTexture(&fourTileTexture);
			break;
		case 5:
			this->setTexture(&fiveTileTexture);
			break;
		case 6:
			this->setTexture(&sixTileTexture);
			break;
		case 7:
			this->setTexture(&sevenTileTexture);
			break;
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
