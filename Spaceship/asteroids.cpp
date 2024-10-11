#include "asteroids.h"


Asteroids::Asteroids(int positionX, int positionY, int speed)
{
    asteroidTexture.loadFromFile("Graphics/a30000.png");
    asteroidSprite.setTexture(asteroidTexture);
    this->positionX = positionX;
    this->positionY = positionY;
    this->speed = speed;
    asteroidSprite.setPosition(positionX, positionY);
    IsActive = true;
    IsHit = false;
}

void Asteroids::DrawAsteroid(sf::RenderWindow& window)
{
    if (IsActive)
    {
        window.draw(asteroidSprite);
    }
}

void Asteroids::Update()
{
    positionY += speed;
    asteroidSprite.setPosition(positionX, positionY);

    if (positionY > 700) 
    {
        IsActive = false;
    }
}

sf::FloatRect Asteroids::getRect()
{
    return asteroidSprite.getGlobalBounds();
}
