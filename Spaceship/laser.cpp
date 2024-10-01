#include "laser.h"

Laser::Laser(Vector2 position, int speed)
{
	laserimage = LoadTexture("Graphics/Kla'ed - Ray.png");
	this->position = position;
	this->speed = speed;
	laseractive = true;
}

void Laser::DrawLaser()
{
	if(laseractive)
	DrawTextureV(laserimage, position, WHITE);
}

void Laser::Update()
{
	position.y -= speed;
	if (position.y < 0)
	{
		laseractive = false;
		
	}
}
