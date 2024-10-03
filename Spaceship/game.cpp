#include "game.h"
#include <raylib.h>
#include<random>

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
	if (Over==false)
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
		Explode();
		Crash();
	}
	
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
	if (GetTime() - LastAsteroidTime >= 2)
	{
		asteroids.push_back(Asteroids( RandomX(),0, 4));
		LastAsteroidTime = GetTime();
	}
	
}

int Game::RandomX()
{

	std::random_device rd;  // a seed source for the random number engine
	std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(50, 700);
	int X = distrib(gen);
	return X;
}

void Game::Explode()
{
	for (auto& laser : spaceship.lasers)
	{
		auto it = asteroids.begin();
		while (it != asteroids.end())
		{
			if (CheckCollisionRecs(it->getrect(), laser.getrect()))
			{
				it = asteroids.erase(it);
				laser.laseractive = false;
			}
			else {
				++it;
			}
		}
	}
}

void Game::Crash()
{
	for (auto it= asteroids.begin();it!=asteroids.end();)
	{
		if (CheckCollisionRecs(it->getrect(), spaceship.getrect()))
		{
			GameOver();
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
