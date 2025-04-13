#pragma once

#include <SFML/Graphics.hpp>

class Tile : public sf::RectangleShape
{
public:
	Tile(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Image& image);
protected:
	sf::Sprite tileSprite;
};
