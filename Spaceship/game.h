#pragma once
#include "spaceship.h"
#include "asteroids.h"
#include <random>

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
	int RandomX();
	double LastAsteroidTime = 0;
	
};