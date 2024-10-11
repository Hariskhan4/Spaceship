#pragma once
#include <SFML/Graphics.hpp>

class Laser
{
public:
    Laser(sf::Vector2f position, int speed);
    void DrawLaser(sf::RenderWindow& window);
    void Update();
    bool laserActive;
    sf::Texture laserTexture;
    sf::Sprite laserSprite;
    sf::Vector2f position;
    sf::FloatRect getRect();

private:
    int speed;
};
