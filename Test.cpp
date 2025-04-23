// created 4/21/2025

#include "Test.hpp"

// created 4/22/2025
// done
Test::Test()
{
	testBombTile();
	testNumberTile();
	testBlankTile();
	testFlag();
	testLose();
}

// created 4/21/2025
// done
void Test::testBombTile()
{
	BombTile testBombTile({ 90, 90 });

	if (testBombTile.getSize().x == 45 && testBombTile.getSize().y == 45) {
		std::cout << "Bomb test case #1 passed" << std::endl;
	}
	else {
		std::cout << "Bomb test case #1 failed" << std::endl;
	}

	if (testBombTile.getPosition().x == 90 && testBombTile.getPosition().y == 90) {
		std::cout << "Bomb test case #2 passed" << std::endl;
	}
	else {
		std::cout << "Bomb test case #2 failed" << std::endl;
	}

	if (testBombTile.getTexture() == &Tile::coveredTileTexture) {
		std::cout << "Bomb test case #3 passed" << std::endl;
	}
	else {
		std::cout << "Bomb test case #3 failed" << std::endl;
	}

	testBombTile.reveal();

	if (testBombTile.getTexture() == &Tile::bombTileTexture) {
		std::cout << "Bomb test case #4 passed" << std::endl;
	}
	else {
		std::cout << "Bomb test case #4 failed" << std::endl;
	}
}

// created 4/22/2025
// done
void Test::testNumberTile()
{
	NumberTile testNumberTile({ 90, 90 }, 5);

	if (testNumberTile.getSize().x == 45 && testNumberTile.getSize().y == 45) {
		std::cout << "Number tile test case #1 passed" << std::endl;
	}
	else {
		std::cout << "Number tile test case #1 failed" << std::endl;
	}

	if (testNumberTile.getPosition().x == 90 && testNumberTile.getPosition().y == 90) {
		std::cout << "Number tile test case #2 passed" << std::endl;
	}
	else {
		std::cout << "Number tile test case #2 failed" << std::endl;
	}

	if (testNumberTile.getTexture() == &Tile::coveredTileTexture) {
		std::cout << "Number tile test case #3 passed" << std::endl;
	}
	else {
		std::cout << "Number tile test case #3 failed" << std::endl;
	}

	testNumberTile.reveal();

	if (testNumberTile.getTexture() == &Tile::fiveTileTexture) {
		std::cout << "Number tile test case #4 passed" << std::endl;
	}
	else {
		std::cout << "Number tile test case #4 failed" << std::endl;
	}
}

// created 4/22/2025
// done
void Test::testBlankTile()
{
	BlankTile testBlankTile({ 90, 90 });

	if (testBlankTile.getSize().x == 45 && testBlankTile.getSize().y == 45) {
		std::cout << "Blank tile test case #1 passed" << std::endl;
	}
	else {
		std::cout << "Blank tile test case #1 failed" << std::endl;
	}

	if (testBlankTile.getPosition().x == 90 && testBlankTile.getPosition().y == 90) {
		std::cout << "Blank tile test case #2 passed" << std::endl;
	}
	else {
		std::cout << "Blank tile test case #2 failed" << std::endl;
	}

	if (testBlankTile.getTexture() == &Tile::coveredTileTexture) {
		std::cout << "Blank tile test case #3 passed" << std::endl;
	}
	else {
		std::cout << "Blank tile test case #3 failed" << std::endl;
	}

	testBlankTile.reveal();

	if (testBlankTile.getTexture() == &Tile::blankTileTexture) {
		std::cout << "Blank tile test case #4 passed" << std::endl;
	}
	else {
		std::cout << "Blank tile test case #4 failed" << std::endl;
	}
}

// created 4/22/2025
void Test::testFlag()
{
	BombTile testTile1({ 90, 90 }), testTile2({ 0, 0 });

	int flagsRemaining = 1;

	testTile1.flag(&flagsRemaining); // should flag testTile1
	testTile2.flag(&flagsRemaining); // should not flag testTile2 (out of flags)

	if (testTile1.getTexture() == &Tile::flagTileTexture) {
		std::cout << "Flag test #1 passed" << std::endl;
	}
	else {
		std::cout << "Flag test #1 failed" << std::endl;
	}

	if (testTile2.getTexture() == &Tile::coveredTileTexture) {
		std::cout << "Flag test #2 passed" << std::endl;
	}
	else {
		std::cout << "Flag test #2 failed" << std::endl;
	}
}

// created 4/22/2025
void Test::testLose()
{
	BombTile testBombTile({ 90, 90 });

	testBombTile.reveal(); // reveals the bomb tile, player loses

	if (testBombTile.revealed()) {
		std::cout << "Lose test passed" << std::endl;
	}
	else {
		std::cout << "Lose test failed" << std::endl;
	}
}
