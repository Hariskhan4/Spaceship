#pragma once
#include <raylib.h>
#include "laser.h"
#include <vector>

class Spaceship
{
public:
	Spaceship();
	~Spaceship();
	void DrawSpaceship();
	void Update();
	void  moveLeft();
	void  moveRight();
	void  moveUp();
	void  moveDown();
	Vector2 position;
	void firelaser();
	std::vector<Laser> lasers;
	Rectangle getrect();

private:
	Texture2D image;
	double LastFireTime;
};