#pragma once
#include <SFML/Graphics.hpp>
#include "laser.h"
#include <vector>

class Spaceship
{
public:
    Spaceship();
    ~Spaceship();
    void DrawSpaceship(sf::RenderWindow& window);
    void Update();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    sf::Vector2f position;
    void fireLaser();
    std::vector<Laser> lasers;
    sf::FloatRect getRect();
    double getElapsedTime();

private:
    sf::Texture texture;
    sf::Sprite sprite;
    double LastFireTime;
};
