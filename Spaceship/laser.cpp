#include "laser.h"

Laser::Laser(sf::Vector2f position, int speed)
{
    laserTexture.loadFromFile("Graphics/Kla'ed - Ray.png");
    laserSprite.setTexture(laserTexture);
    this->position = position;
    this->speed = speed;
    laserSprite.setPosition(position);
    laserActive = true;
}

void Laser::DrawLaser(sf::RenderWindow& window)
{
    if (laserActive)
    {
        window.draw(laserSprite);
    }
    
}

void Laser::Update()
{
    position.y -= speed;
    laserSprite.setPosition(position);

    if (position.y < 0)
    {
        laserActive = false;
    }
}

sf::FloatRect Laser::getRect()
{
    return laserSprite.getGlobalBounds();
}
