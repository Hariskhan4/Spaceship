#pragma once
#include "spaceship.h"

class Game
{
public:
	Game();
	~Game();
	void DrawGame();
	void Update();
	void PlayerInput();
private:
	Spaceship spaceship;
	void DeleteInActiveLasers();
};