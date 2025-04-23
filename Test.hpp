// created 4/21/2025

#pragma once

#include <iostream>

#include "Tile.hpp"
#include "BombTile.hpp"
#include "NumberTile.hpp"
#include "BlankTile.hpp"
#include "Game.hpp"

class Test
{
public:
	Test();
private:
	void testBombTile();
	void testNumberTile();
	void testBlankTile();
	void testFlag();
	void testLose();
};