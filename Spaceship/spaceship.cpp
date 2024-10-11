#include "spaceship.h"
#include <iostream>
#include <chrono>

Spaceship::Spaceship()
{
    texture.loadFromFile("Graphics/Kla'ed - Battlecruiser - Base.png");
    sprite.setTexture(texture);
    position.x = (750 - texture.getSize().x) / 2; 
    position.y = 700 - texture.getSize().y; 
    LastFireTime = 0.0;
}

Spaceship::~Spaceship()
{
    
}

void Spaceship::DrawSpaceship(sf::RenderWindow& window)
{
    sprite.setPosition(position);
    window.draw(sprite);
}

void Spaceship::Update()
{
    
}

void Spaceship::moveLeft()
{
    position.x -= 12;
    if (position.x < 0)
        position.x = 0;
}

void Spaceship::moveRight()
{
    position.x += 12;
    if (position.x > 750 - texture.getSize().x) 
        position.x = 750 - texture.getSize().x;
}

void Spaceship::moveUp()
{
    position.y -= 12;
    if (position.y < 0)
        position.y = 0;
}

void Spaceship::moveDown()
{
    position.y += 12;
    if (position.y > 700 - texture.getSize().y) 
        position.y = 700 - texture.getSize().y;
}

void Spaceship::fireLaser()
{
    if (getElapsedTime()-LastFireTime >= 0.35) {
        lasers.push_back(Laser({ position.x + texture.getSize().x / 2 - 35, position.y }, 7));
        LastFireTime = getElapsedTime();
    }
}

sf::FloatRect Spaceship::getRect()
{
    return sprite.getGlobalBounds();
}

double Spaceship::getElapsedTime()
{
    
    return std::chrono::duration<double>(std::chrono::system_clock::now().time_since_epoch()).count();
}
