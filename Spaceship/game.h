#pragma once
#include "spaceship.h"
#include "asteroids.h"

class Game
{
public:
	Game();
	~Game();
	void DrawGame();
	void Update();
	void PlayerInput();
	std::vector<Asteroids> asteroids;
private:
	Spaceship spaceship;
	void DeleteInActiveLasers();
	void DeleteInActiveAsteroids();
	void GenerateAsteroid();
	double LastAsteroidTime = 0;;
	
};