#include <SFML/Graphics.hpp>
#include <iostream>


class MainMenu
{
private:
    sf::Font font;
    sf::Text titleText;
    sf::Text menuItems[3];
    int selectedItemIndex;


public:
    MainMenu() : selectedItemIndex(0)
    {
        
        if (!font.loadFromFile("COME BACK"))//WE NEED A FONT CHOICE
        {
           std::cerr << "Error: Could not load \n";
        }

        //Title Text
        titleText.setFont(font);
        titleText.setString("***Game-Menu***");
        titleText.setCharacterSize(10);
        titleText.setFillColor(sf::Color::Grey);
        titleText.setPosition(150, 50);

        // Main Menu items - note to self adjust font size- wasnt pulling up correctly.
        std::string items[3] = { "START", "DIRECTIONS", "EXIT" };

        for (int i = 0; i < 3; i++)
        {
            menuItems[i].setFont(font);
            menuItems[i].setString(items[i]);
            menuItems[i].setCharacterSize(30);
            menuItems[i].setPosition(300, 120 + i * 60);
            menuItems[i].setFillColor(i == 0 ? sf::Color::Grey : sf::Color::White);
        }
    }


    // DRAWS OUR MENU VISUALLY ONTO OUR SCREEN
    void Draw(sf::RenderWindow& window)
    {
        window.draw(titleText);
        for (int i = 0; i < 3; i++)
        {
            window.draw(menuItems[i]);
        }
    }


    // SELECTION ABILITY (UP)
    void MoveUp()
    {
        if (selectedItemIndex - 1 >= 0)
        {
            menuItems[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex--;
            menuItems[selectedItemIndex].setFillColor(sf::Color::Yellow);
        }
    }


    // SELECTION ABILITY (DOWN)
    void MoveDown()
    {
        if (selectedItemIndex + 1 < 3)
        {
            menuItems[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex++;
            menuItems[selectedItemIndex].setFillColor(sf::Color::Yellow);
        }
    }


    // Returns our currently selected item// i need to come badck and fix shape
    int getSelectedItem()
       const
    {
        return selectedItemIndex;
    }
};


int main()
{
    // Create an SFML window   WE CAN COME BACK AND FIX THE FONT TO MATCH
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Menu with Background & Consolas Font");

    // Load Our MINESWEEPER background image (minesweeperTilesTitle.png)
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("minesweeperTilesTitle.png"))
    {
        std::cerr << "ERROR: Could Not Find File\n";
        return -1;
    }


    // THIS ADDS OUR 2-D level
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    
    
    // WE NEED TO SCALE THE BACK
    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);



    // Initialize Menu
    MainMenu;

    // This Runs Our Main Loop
    //Open our program and "WHILE ITS OPEN"... it will do blah blah blah blah 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

       //Dont Forget to make a close
            if (event.type == sf::Event::Closed)
                window.close();


         //Set Up how we are gonna respond from the keys 
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                    menu.MoveUp();
                else if (event.key.code == sf::Keyboard::Down)
                    menu.moveDown();
                else if (event.key.code == sf::Keyboard::Return)
                {
                    int selection = menu.getSelectedItem();
                    if (selection == 0)
                    {
                        std::cout << "START selected.\n";
                        // Insert the logic to start the game.
                    }
                    else if (selection == 1)
                    {
                        std::cout << "DIRECTIONS selected\n";
                        //NOW TO ADD THE RULES IN A SIMPLE WAY -------COMEBACK TO THIS 
                        printf("MINESWEEPER: HOW TO PLAY:\n 1.SOMETHING\n 2.SOMETHING.\n 3.SOMETHING\n");
                    }
                    else if (selection == 2)
                    {
                        std::cout << "EXIT\n";
                        window.close();
                    }
                }
            }
        }
        window.clear();
        //Draw The Image 
        window.draw(backgroundSprite);
        //Now we throw our secont layer over the top with our menu
        menu.draw(window);//-------DOUBLE CHECK NAMING CLATURE FOR THIS BECAUSE I CHANGED IT 
        window.display();
    }

    return 0;

}

