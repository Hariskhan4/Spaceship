#include "asteroids.h"
#include <random>

Asteroids::Asteroids(int positionX,int positionY, int speed)
{
	asteroidimage = LoadTexture("Graphics/a30000.png");
	this->positionX = positionX;
	this->positionY = positionY;
	this->speed = speed;
	IsActive = true;
	IsHit = false;
}

void Asteroids::DrawAsteroid()
{
	DrawTexture(asteroidimage,positionX,positionY, WHITE);
}

void Asteroids::Update()
{
	positionY += speed;
	if (positionY > GetScreenHeight() - asteroidimage.height)
	{
		IsActive = false;
	}
}

