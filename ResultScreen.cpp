#include <SFML/Graphics.hpp>

// Function to display the result screen
void showResultScreen(sf::RenderWindow& &window, bool gameWon)
{
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile(minesweeperTilesTitle.png))
    {
        return;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

    sf::Font font;
    if (!font.loadFromFile(".ttf"))//COME BACK AND SET FONT
    {
        return;
    }

    sf::Text resultText;
    resultText.setFont(font);
    resultText.setCharacterSize(50);
    resultText.setFillColor(gameWon ? sf::Color::Red : sf::Color::Red);
    resultText.setString(gameWon ? "You Won!\n Good Job on Clearing the Mines" : "BOOM!\nGame Over!");
    resultText.setPosition(200, 250);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(backgroundSprite);
        window.draw(resultText);
        window.display();
    }
}
