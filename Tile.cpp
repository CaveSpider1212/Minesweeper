// created 4/17/2025

#include "Tile.hpp"

sf::Texture Tile::coveredTileTexture(sf::Image("Images/coveredTile.png"));
sf::Texture Tile::blankTileTexture(sf::Image("Images/minesweeperTilesBlank.png"));
sf::Texture Tile::bombTileTexture(sf::Image("Images/minesweeperTilesBomb.png"));
sf::Texture Tile::oneTileTexture(sf::Image("Images/minesweeperTiles1.png"));
sf::Texture Tile::twoTileTexture(sf::Image("Images/minesweeperTiles2.png"));
sf::Texture Tile::threeTileTexture(sf::Image("Images/minesweeperTiles3.png"));
sf::Texture Tile::fourTileTexture(sf::Image("Images/minesweeperTiles4.png"));
sf::Texture Tile::fiveTileTexture(sf::Image("Images/minesweeperTiles5.png"));
sf::Texture Tile::sixTileTexture(sf::Image("Images/minesweeperTiles6.png"));
sf::Texture Tile::sevenTileTexture(sf::Image("Images/minesweeperTiles7.png"));
sf::Texture Tile::flagTileTexture(sf::Image("Images/flag.png"));

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