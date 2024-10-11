#include "Game.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>

Game::Game()
{

}

Game::~Game()
{

}

void Game::DrawGame (sf::RenderWindow& window)
{
    if (!Over)
    {
        spaceship.DrawSpaceship(window);

        // Draw lasers
        for (auto& laser : spaceship.lasers)
        {
            laser.DrawLaser(window);
        }

        // Generate and draw asteroids
        GenerateAsteroid();
        for (auto& asteroid : asteroids)
        {
            asteroid.DrawAsteroid(window);
        }
    }
    
}

void Game::Update()
{
    if (!Over)
    {
        // Update lasers
        for (auto& laser : spaceship.lasers)
        {
            laser.Update();
        }
        DeleteInActiveLasers();

        // Update asteroids
        for (auto& asteroid : asteroids)
        {
            asteroid.Update();
        }
        DeleteInActiveAsteroids();

        // Check for explosions or crashes
        Explode();
        Crash();
    }
}

void Game::PlayerInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        spaceship.moveDown();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        spaceship.moveUp();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        spaceship.moveRight();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        spaceship.moveLeft();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        spaceship.fireLaser();
}

void Game::DeleteInActiveLasers()
{
    for (auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();)
    {
        if (!it->laserActive)
        {
            it = spaceship.lasers.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Game::DeleteInActiveAsteroids()
{
    for (auto it = asteroids.begin(); it != asteroids.end();)
    {
        if (!it->IsActive)
        {
            it = asteroids.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Game::GenerateAsteroid()
{
    double currentTime = std::chrono::duration<double>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (currentTime - LastAsteroidTime >= 2) // Generate asteroids every 2 seconds
    {
        asteroids.push_back(Asteroids(RandomX(), 0, 4)); 
        LastAsteroidTime = currentTime;
    }
}

int Game::RandomX()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(50, 700); 
    return distrib(gen);
}

void Game::Explode()
{
    for (auto& laser : spaceship.lasers)
    {
        auto it = asteroids.begin();
        while (it != asteroids.end())
        {
            if (laser.laserActive && it->IsActive && laser.getRect().intersects(it->getRect()))
            {
                it = asteroids.erase(it);
                laser.laserActive = false;
            }
            else {
                ++it;
            }
        }
    }
}

void Game::Crash()
{
    for (auto it = asteroids.begin(); it != asteroids.end();)
    {
        if (it->IsActive && spaceship.getRect().intersects(it->getRect()))
        {
            GameOver();
            return; // Exit to prevent further checks once game is over
        }
        else {
            ++it;
        }
    }
}

void Game::GameOver()
{
    Over = true;
    
}
