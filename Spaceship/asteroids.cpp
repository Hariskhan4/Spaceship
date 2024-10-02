#include "asteroids.h"

Asteroids::Asteroids(Vector2 position, int speed)
{
	asteroidimage = LoadTexture("Graphics/a30000.png");
	this->position = position;
	this->speed = speed;
	IsActive = true;
	IsHit = false;
}

void Asteroids::DrawAsteroid()
{
	DrawTextureV(asteroidimage,position, WHITE);
}

void Asteroids::Update()
{
	position.y += 7;
	if (position.y > GetScreenHeight() - asteroidimage.height)
	{
		IsActive = false;
	}
}
