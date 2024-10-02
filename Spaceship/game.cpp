#include "game.h"
#include <raylib.h>

Game::Game()
{

}

Game::~Game()
{

}

void Game::DrawGame()
{
	spaceship.DrawSpaceship();
	for (auto& laser : spaceship.lasers)
	{
		laser.DrawLaser();
	}
	GenerateAsteroid();
	for (auto& asteroid : asteroids)
	{
		asteroid.DrawAsteroid();
	}
}

void Game::Update()
{
	for (auto& laser : spaceship.lasers)
	{
		laser.Update();
	}
	DeleteInActiveLasers();
	for (auto& asteroid : asteroids)
	{
		asteroid.Update();
	}
	DeleteInActiveAsteroids();
}

void Game::PlayerInput()
{
	if (IsKeyDown(KEY_DOWN)) spaceship.moveDown();
	else if (IsKeyDown(KEY_UP)) spaceship.moveUp();
	else if (IsKeyDown(KEY_RIGHT)) spaceship.moveRight();
	else if (IsKeyDown(KEY_LEFT)) spaceship.moveLeft();
	else if (IsKeyDown(KEY_SPACE)) spaceship.firelaser();

}

void Game::DeleteInActiveLasers()
{
	for (auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();)
	{
		if (!it->laseractive)
		{
			it=spaceship.lasers.erase(it);
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
	if (GetTime() - LastAsteroidTime >= 0.35)
	{
		asteroids.push_back(Asteroids({ 100,100 }, 7));
		LastAsteroidTime = GetTime();
	}
	
}
