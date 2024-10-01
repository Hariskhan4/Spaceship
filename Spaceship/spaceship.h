#pragma once
#include <raylib.h>
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
private:
	Texture2D image;
};