#pragma once
#include <raylib.h>
#include <vector>

class Asteroids
{
public:
	Asteroids(int positionX,int positionY,int speed);
	void DrawAsteroid();
	void Update();
	bool IsHit;
	bool IsActive;


private:
	int positionX;
	int positionY;
	int speed;
	Texture2D asteroidimage;
};