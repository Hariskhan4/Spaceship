#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Asteroids
{
public:
    Asteroids(int positionX, int positionY, int speed);
    void DrawAsteroid(sf::RenderWindow& window);
    void Update();
    bool IsHit;
    bool IsActive;
    int positionX;
    int positionY;
    sf::FloatRect getRect();

private:
    int speed;
    sf::Texture asteroidTexture;
    sf::Sprite asteroidSprite;
};
