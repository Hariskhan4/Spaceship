#pragma once
#include <raylib.h>
#include <vector>

class Asteroids
{
public:
	Asteroids(Vector2 position,int speed);
	void DrawAsteroid();
	void Update();
	bool IsHit;
	bool IsActive;


private:
	Vector2 position;
	int speed;
	Texture2D asteroidimage;
};