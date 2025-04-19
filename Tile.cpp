// created 4/17/2025

#include "Tile.hpp"

// created 4/15/2025
// done
void Tile::draw(sf::RenderWindow& window)
{
	window.draw(*this);
}

// created 4/18/2025
// done
bool Tile::revealed(void)
{
	return isRevealed;
}

// created 4/19/2025
// done
bool Tile::isflagged(void)
{
	return flagged;
}

// created 4/17/2025
// done
int Tile::getStartX()
{
	return startX;
}

// created 4/17/2025
// done
int Tile::getStartY()
{
	return startY;
}

// created 4/17/2025
// done
int Tile::getEndX()
{
	return endX;
}

// created 4/17/2025
// done
int Tile::getEndY()
{
	return endY;
}