#include <raylib.h>
#include "game.h"

int main()
{
	int windowWidth = 750;
	int windowHeight = 700;
	Color maroon = { 190, 33, 55, 255 };
	InitWindow(windowWidth, windowHeight, "Spaceship");
	Texture2D background= LoadTexture("Graphics/Space Background2.png");
	SetTargetFPS(60);
	Game game;
	
	while (WindowShouldClose() == false)
	{
		game.PlayerInput();
		game.Update();
		BeginDrawing();
		ClearBackground(maroon);
		DrawTexture(background, 0, 0, WHITE);
		game.DrawGame();
		EndDrawing();
	}





	CloseWindow();
}