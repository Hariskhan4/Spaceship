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
	Vector2 position;
	Rectangle getrect();
private:
	
	int speed;

};