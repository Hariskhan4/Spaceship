#pragma once
#include <raylib.h>

class Laser
{
public:
	Laser(Vector2 position,int speed );
	void DrawLaser();
	void Update();
	bool laseractive;
	Texture2D laserimage;
private:
	Vector2 position;
	int speed;

};