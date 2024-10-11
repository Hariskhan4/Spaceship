#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    int windowWidth = 750;
    int windowHeight = 700;

    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Spaceship");
    window.setFramerateLimit(60);

    // Load background texture
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("Graphics/Space Background2.png");
    sf::Sprite backgroundSprite(backgroundTexture);

    Game game;

    // Main game loop
    while (window.isOpen())
    {
        // Handle window events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Player input
        game.PlayerInput();

        // Update game logic
        game.Update();

        // Render everything
        window.clear(sf::Color(190, 33, 55)); // Maroon background
        window.draw(backgroundSprite); // Draw background
        game.DrawGame(window); // Draw game objects
        window.display();

    }

    return 0;
}
