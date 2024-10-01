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
}

void Game::PlayerInput()
{
	if (IsKeyDown(KEY_DOWN)) spaceship.moveDown();
	if (IsKeyDown(KEY_UP)) spaceship.moveUp();
	if (IsKeyDown(KEY_RIGHT)) spaceship.moveRight();
	if (IsKeyDown(KEY_LEFT)) spaceship.moveLeft();
}
