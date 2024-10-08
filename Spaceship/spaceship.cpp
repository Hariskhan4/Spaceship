#include "spaceship.h"

Spaceship::Spaceship()
{
	image = LoadTexture("Graphics/Kla'ed - Battlecruiser - Base.png");
	position.x = (GetScreenWidth()-image.width)/2;
	position.y = GetScreenHeight()-image.height;
	LastFireTime = 0.0;
}

Spaceship::~Spaceship()
{
	UnloadTexture(image);
}

void Spaceship::DrawSpaceship()
{
	DrawTextureV(image, position, WHITE);
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
	if (position.x > GetScreenWidth()-image.width)
		position.x = GetScreenWidth() - image.width;
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
	if (position.y > GetScreenHeight() - image.height)
		position.y = GetScreenHeight() - image.height;
}

void Spaceship::firelaser()
{
	if (GetTime() - LastFireTime >= 0.35) {
		lasers.push_back(Laser({ (position.x + image.width / 2) - 35,position.y }, 7));
		LastFireTime = GetTime();
	}
	
}

Rectangle Spaceship::getrect()
{
	return {position.x,position.y,float(image.width),float(image.height)};
}
