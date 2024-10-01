#include "game.h"

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
}

void Game::Update()
{
	for (auto& laser : spaceship.lasers)
	{
		laser.Update();
	}
	DeleteInActiveLasers();
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
